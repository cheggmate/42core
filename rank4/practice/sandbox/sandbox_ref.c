/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox_my.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoo <wchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by  exit, alar       #+#    #+#             */
/*   Updated: 2026/02/02 15:59:21 by wchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>    /* bool, true, false */
#include <stdio.h>      /* printf() */
#include <signal.h>     /* sigaction, sig_atomic_t, SIGALRM, kill() */
#include <sys/wait.h>   /* waitpid(), WIFEXITED, WEXITSTATUS, WIFSIGNALED, WTERMSIG */
#include <unistd.h>     /* fork(), alarm() */
#include <string.h>     /* strsignal() */
#include <stdlib.h>     /* exit() */

/* ========================================================================== */
/*                          GLOBAL VARIABLES                                  */
/* ========================================================================== */

/*
** These global variables are used to communicate between the signal handler
** and the main function. They must be volatile because they can be modified
** asynchronously by the signal handler.
**
** sig_atomic_t is a special type guaranteed to be read/written atomically,
** meaning the signal handler won't corrupt the value mid-access.
*/

/* Set to 1 when the timeout alarm fires */
static volatile sig_atomic_t g_timed_out = 0;

/* Stores the child's PID so the signal handler can kill it */
static volatile sig_atomic_t g_child_pid = -1;

/* ========================================================================== */
/*                          SIGNAL HANDLER                                    */
/* ========================================================================== */

/*
** alarm_handler - Called when SIGALRM is received (timeout occurred)
** 
** This function runs asynchronously when the alarm timer expires.
** It sets a flag and kills the child process that's taking too long.
** 
** @param sig: The signal number (unused, but required by signal handler signature)
** 
** IMPORTANT: Signal handlers should be very simple - only call async-signal-safe
** functions. kill() is async-signal-safe.
*/
static void alarm_handler(int sig)
{
    (void)sig;              /* Suppress unused parameter warning */
    g_timed_out = 1;        /* Mark that we timed out */
    if (g_child_pid > 0)    /* If we have a valid child PID */
        kill((pid_t)g_child_pid, SIGKILL);  /* Forcefully terminate it */
}

/* ========================================================================== */
/*                          MAIN FUNCTION                                     */
/* ========================================================================== */

/*
** sandbox - Test if a function is "nice" or "bad"
** 
** A function is considered "nice" if it:
** - Exits normally with exit code 0
** - Completes within the timeout period
** - Doesn't crash or receive any signal
** 
** A function is considered "bad" if it:
** - Exits with a non-zero exit code
** - Times out (runs longer than 'timeout' seconds)
** - Crashes (segfault, abort, etc.)
** - Is killed by any signal
** 
** @param f: Pointer to the function to test (takes no args, returns nothing)
** @param timeout: Maximum seconds to allow the function to run
** @param verbose: If true, print descriptive messages
** @return: 1 if nice, 0 if bad, -1 if sandbox itself had an error
*/
int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    struct sigaction    sa;     /* For setting up signal handler */
    pid_t               pid;    /* Child process ID */
    int                 status; /* Child's exit status from waitpid */

    /* ===== VALIDATION ===== */
    if (!f)                     /* NULL function pointer is an error */
        return (-1);

    /* Reset global state from any previous calls */
    g_timed_out = 0;
    g_child_pid = -1;

    /* ===== FORK CHILD PROCESS ===== */
    /*
    ** We run the function in a child process so that:
    ** 1. If it crashes, it doesn't crash our program
    ** 2. If it hangs, we can kill it
    ** 3. We can monitor what happens to it
    */
    pid = fork();
    if (pid < 0)                /* Fork failed */
        return (-1);

    /* ===== CHILD PROCESS ===== */
    if (pid == 0)
    {
        /*
        ** Execute the function.
        ** If it returns normally, exit with code 0.
        ** If it crashes, the OS will terminate us with a signal.
        */
        f();
        exit(0);                /* Function completed successfully */
    }

    /* ===== PARENT PROCESS ===== */
    /*
    ** From here on, we're the parent monitoring the child.
    */

    /* Save the child PID so signal handler can access it */
    g_child_pid = pid;

    /* ----- Set up SIGALRM handler for timeout ----- */
    /*
    ** sigaction() is the modern, reliable way to set up signal handlers.
    ** 
    ** sa.sa_handler = our handler function
    ** sa.sa_mask = signals to block during handler (empty = none)
    ** sa.sa_flags = 0 (no special behavior)
    */
    sigemptyset(&sa.sa_mask);   /* Don't block additional signals */
    sa.sa_flags = 0;            /* Default behavior */
    sa.sa_handler = alarm_handler;

    if (sigaction(SIGALRM, &sa, NULL) == -1)
    {
        /* sigaction failed - clean up child and report error */
        kill(pid, SIGKILL);
        waitpid(pid, NULL, 0);
        g_child_pid = -1;
        return (-1);
    }

    /* ----- Start the timeout timer ----- */
    /*
    ** alarm(n) sets a timer for n seconds.
    ** When it expires, SIGALRM is sent to this process.
    ** Our handler will then be called.
    */
    alarm(timeout);

    /* ----- Wait for child to finish ----- */
    /*
    ** waitpid() blocks until the child terminates.
    ** The 'status' variable will contain information about how it terminated.
    */
    if (waitpid(pid, &status, 0) == -1)
    {
        alarm(0);               /* Cancel timer */
        g_child_pid = -1;
        return (-1);
    }

    /* ----- Child is done, cancel the timer ----- */
    alarm(0);                   /* Cancel any pending alarm */
    g_child_pid = -1;           /* Clear the saved PID */

    /* ===== ANALYZE THE RESULT ===== */

    /* ----- Case 1: Timeout occurred ----- */
    if (g_timed_out)
    {
        if (verbose)
            printf("Bad function: timed out after %u seconds\n", timeout);
        return (0);             /* Bad function */
    }

    /* ----- Case 2: Child exited normally ----- */
    /*
    ** WIFEXITED(status) is true if child called exit() or returned from main
    ** WEXITSTATUS(status) extracts the exit code
    */
    if (WIFEXITED(status))
    {
        int code = WEXITSTATUS(status);
        if (code == 0)
        {
            /* Exited with code 0 = success */
            if (verbose)
                printf("Nice function!\n");
            return (1);         /* Nice function! */
        }
        else
        {
            /* Exited with non-zero code = failure */
            if (verbose)
                printf("Bad function: exited with code %d\n", code);
            return (0);         /* Bad function */
        }
    }

    /* ----- Case 3: Child was killed by a signal ----- */
    /*
    ** WIFSIGNALED(status) is true if child was killed by a signal
    ** WTERMSIG(status) extracts which signal killed it
    ** strsignal() converts signal number to human-readable string
    */
    if (WIFSIGNALED(status))
    {
        int sig = WTERMSIG(status);
        if (verbose)
            printf("Bad function: %s\n", strsignal(sig));
        return (0);             /* Bad function */
    }

    /* Should not reach here, but just in case */
    return (-1);
}

/* ========================================================================== */
/*                              TEST CODE                                     */
/* ========================================================================== */

/* Test functions with different behaviors */

/* Nice function - returns immediately */
// void ok_func(void)
// {
//     /* Does nothing, returns successfully */
// }

// /* Bad function - infinite loop (will timeout) */
// void infinite_func(void)
// {
//     while (1)
//         ;                       /* Loop forever */
// }

// /* Bad function - exits with error code */
// void bad_exit_func(void)
// {
//     exit(42);                   /* Non-zero exit code */
// }

// /* Bad function - causes segmentation fault */
// void segfault_func(void)
// {
//     int *p = NULL;
//     *p = 42;                    /* Dereference NULL pointer = SIGSEGV */
// }

// /* Bad function - calls abort() */
// void abort_func(void)
// {
//     abort();                    /* Sends SIGABRT to self */
// }

// /* Helper to run a test */
// void run_test(void (*f)(void), unsigned int timeout, const char *name)
// {
//     printf("=== Testing: %s (timeout: %us) ===\n", name, timeout);
//     int result = sandbox(f, timeout, true);
//     printf("sandbox() returned: %d\n\n", result);
// }

// int main(void)
// {
//     run_test(ok_func, 2, "ok_func (nice, immediate return)");
//     run_test(infinite_func, 2, "infinite_func (infinite loop)");
//     run_test(bad_exit_func, 2, "bad_exit_func (exit code 42)");
//     run_test(segfault_func, 2, "segfault_func (NULL dereference)");
//     run_test(abort_func, 2, "abort_func (calls abort)");

//     return (0);
// }
