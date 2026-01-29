/*
Assignment name		:	sandbox
Expected files		:	sandbox.c
Allowed functions	:	fork, waitpid, exit, alarm, sigaction, kill,
						printf, strsignal, errno
===============================================================================

Write the following function:

#include <stdbool.h>
int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)

This function must test if the function f is a nice function or a bad function,
you will return 1 if f is nice , 0 if f is bad or -1 in case of an error in
your function.

A function is considered bad if it is terminated or stopped by a signal
(segfault, abort...), if it exit with any other exit code than 0 or if it
times out.

If verbose is true, you must write the appropriate message among the following:

"Nice function!\n"
"Bad function: exited with code <exit_code>\n"
"Bad function: <signal description>\n"
"Bad function: timed out after <timeout> seconds\n"

You must not leak processes (even in zombie state, this will be checked using
wait).

We will test your code with very bad functions.
*/

// sandbox.c

#include <unistd.h>     // fork(), alarm(), _exit()
#include <sys/wait.h>   // waitpid(), WIFEXITED, WIFSIGNALED, WEXITSTATUS, WTERMSIG
#include <signal.h>     // sigaction, SIGALRM, SIGKILL, struct sigaction
#include <stdbool.h>    // bool
#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include <errno.h>      // errno, EINTR
#include <string.h>     // strsignal()

// Handler vide pour interrompre waitpid() sur SIGALRM
static void do_nothing(int sig)
{
    (void)sig;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    pid_t pid = fork();
    if (pid < 0)
        return -1;

    if (pid == 0)
    {
        // --- Processus enfant ---
        alarm(timeout);
        f();
        _exit(0);
    }

    // --- Processus parent ---
    struct sigaction sa = {0};
    sa.sa_handler = do_nothing;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGALRM, &sa, NULL) < 0)
        return -1;

    alarm(timeout);

    int status;
    pid_t r = waitpid(pid, &status, 0);
    if (r < 0)
    {
        if (errno == EINTR)
        {
            // Timeout : kill et récolte de l'enfant
            kill(pid, SIGKILL);
            waitpid(pid, NULL, 0);
            if (verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
            return 0;
        }
        return -1;
    }

    // Annuler l'alarme restante
    alarm(0);

    if (WIFEXITED(status))
    {
        int code = WEXITSTATUS(status);
        if (code == 0)
        {
            if (verbose)
                printf("Nice function!\n");
            return 1;
        }
        if (verbose)
            printf("Bad function: exited with code %d\n", code);
        return 0;
    }

    if (WIFSIGNALED(status))
    {
        int sig = WTERMSIG(status);
        if (sig == SIGALRM)
        {
            if (verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
        }
        else
        {
            if (verbose)
                printf("Bad function: %s\n", strsignal(sig));
        }
        return 0;
    }

    // Cas imprévu
    return -1;
}


/*void ok_f(void)
{
	printf("noice. ");
}

void inf_f(void)
{
	while (1)
		;
}

void bad_exit(void)
{
	exit(41);
}

void suicide_f(void)
{
    kill(getpid(), SIGKILL);
    sleep(10);
}

void fast_print_f(void)
{
    printf("fast_print_f executed\n");
}

void abort_f(void)
{
    abort();
}

// 7. Fonction qui fait un stop avec SIGSTOP (ne se termine pas)
void stop_f(void)
{
    raise(SIGSTOP);
    // Le processus sera stoppé et jamais repris => timeout dans sandbox
    sleep(10); // Juste pour être sûr si repris
}

void segfault_f(void)
{
    int *p = NULL;
    *p = 42;
}

void cancel_alarm(void)
{
	struct sigaction ca;
	ca.sa_handler = SIG_IGN;
	sigaction(SIGALRM, &ca, NULL);

	sleep(5);
	printf("f waited 5 seconds, should be terminated before by alarm set in parent process if timeout < 5\n");
}

void leak_f(void)
{
	int *p = NULL;
	*p = 4;
}

void test_func(void (*f)(void), unsigned int timeout, const char* name)
{
    printf("==== Test : %s (timeout %us) ====\n", name, timeout);
    int res = sandbox(f, timeout, true);
    printf("Result = %d\n\n", res);
}

int main(void)
{
    test_func(ok_f, 2, "ok_f (nice function, immediate return)");

    test_func(inf_f, 2, "inf_f (infinite loop, should timeout)");

    test_func(bad_exit, 2, "bad_exit (exit with code 41)");

    test_func(cancel_alarm, 2, "cancel_alarm (ignore SIGALRM, sleep 5s)");

    test_func(segfault_f, 2, "segfault_f (segmentation fault)");

    test_func(abort_f, 2, "abort_f (abort signal SIGABRT)");

    test_func(stop_f, 2, "stop_f (stops self with SIGSTOP, never continues)");

    test_func(suicide_f, 2, "suicide_f (kills self with SIGKILL)");

    test_func(fast_print_f, 2, "fast_print_f (quick print + return 0)");

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* --- Test Functions to pass into sandbox --- */

void f_nice(void) {
    printf("Child: I'm being a good boy.\n");
}

void f_bad_exit(void) {
    printf("Child: I'm exiting with error code 42.\n");
    exit(42);
}

void f_segfault(void) {
    printf("Child: I'm going to segfault now...\n");
    int *p = NULL;
    *p = 1337;
}

void f_timeout(void) {
    printf("Child: I'm going to sleep forever (infinite loop)...\n");
    while (1) {
        // Just spinning
    }
}

void f_abort(void) {
    printf("Child: Calling abort()...\n");
    abort();
}

/* --- Helper to run and label tests --- */

void run_test(const char *test_name, void (*f)(void), unsigned int timeout) {
    printf("--- Testing: %s ---\n", test_name);
    int result = sandbox(f, timeout, true);
    printf("Return Value: %d\n\n", result);
}

/* --- Main Test Runner --- */

int main(void) {
    // Test 1: Standard successful run
    run_test("NICE FUNCTION", f_nice, 2);

    // Test 2: Custom exit code
    run_test("EXIT CODE 42", f_bad_exit, 2);

    // Test 3: Crash (Segmentation Fault)
    run_test("SEGFAULT", f_segfault, 2);

    // Test 4: Hang / Timeout
    // Note: This will take 'timeout' seconds to complete
    run_test("TIMEOUT (2s)", f_timeout, 2);

    // Test 5: Abort signal
    run_test("ABORT", f_abort, 2);

    // Test 6: Short timeout for a "slow" nice function
    // (If the function is slow but valid, it should still be marked bad due to timeout)
    run_test("SLOW FUNCTION (TIMEOUT 1s)", f_timeout, 1);

    return 0;
}