/* ************************************************************************** */
/*                          MY_PICOSHELL.C                                    */
/*                                                                            */
/*  Standard annotated version of picoshell - a mini shell pipeline executor  */
/*  This implements a function that executes commands connected by pipes,     */
/*  similar to how "cmd1 | cmd2 | cmd3" works in a real shell.                */
/*                                                                            */
/*  Allowed functions: close, fork, wait, exit, execvp, dup2, pipe            */
/* ************************************************************************** */

#include <unistd.h>     /* fork(), execvp(), pipe(), dup2(), close() */
#include <sys/types.h>  /* pid_t type definition */
#include <sys/wait.h>   /* wait(), WIFEXITED, WEXITSTATUS macros */
#include <stdlib.h>     /* exit() function */

/*
** picoshell - Execute a pipeline of commands
** 
** @param cmds: A NULL-terminated array of commands. Each command is itself
**              a NULL-terminated array of strings (argv format).
**              Example: {{"ls", "-l", NULL}, {"grep", "txt", NULL}, NULL}
**
** @return: 0 on success, 1 on any error
**
** How it works:
** 1. For each command in the array, create a child process using fork()
** 2. Connect commands with pipes: output of cmd[i] goes to input of cmd[i+1]
** 3. Each child process executes its command using execvp()
** 4. Parent waits for all children to complete
*/
int picoshell(char **cmds[])
{
    int     i;          /* Index to iterate through array of commands */
    int     in_fd;      /* File descriptor for input from previous command's output */
    int     fd[2];      /* Pipe file descriptors: fd[0]=read end, fd[1]=write end */
    pid_t   pid;        /* Process ID returned by fork() */

    i = 0;              /* Start with the first command (index 0) */
    in_fd = 0;          /* Initially 0 (stdin), later holds previous pipe's read end */

    /* ===== MAIN LOOP: Process each command in the array ===== */
    while (cmds[i])     /* Loop while there are commands to process (until NULL) */
    {
        /* ----- STEP 1: Create pipe if there's a next command ----- */
        /* If cmds[i+1] exists (not the last command), create a pipe */
        /* pipe(fd) creates two connected file descriptors: fd[0] for reading, fd[1] for writing */
        if (cmds[i + 1] && pipe(fd) < 0)    /* If next command exists AND pipe creation fails */
            return (1);                      /* Return error immediately */

        /* ----- STEP 2: Fork to create child process ----- */
        /* fork() creates an exact copy of the current process */
        /* Returns: 0 in child, child's PID in parent, -1 on error */
        pid = fork();
        if (pid < 0)        /* Fork failed */
            return (1);     /* Return error */

        /* ----- STEP 3: Child process code (pid == 0) ----- */
        if (pid == 0)
        {
            /* --- 3a: Redirect input from previous pipe if not first command --- */
            /* If in_fd != 0, it means this is not the first command */
            /* We need to read input from the previous command's output */
            if (in_fd != 0)
            {
                /* dup2(in_fd, 0) makes stdin (fd=0) a copy of in_fd */
                /* After this, reading from stdin will read from the pipe */
                dup2(in_fd, 0);     /* Redirect stdin to read from previous pipe */
                close(in_fd);       /* Close original fd (no longer needed after dup2) */
            }

            /* --- 3b: Redirect output to current pipe if not last command --- */
            /* If there's a next command, send our output to the pipe */
            if (cmds[i + 1])
            {
                /* dup2(fd[1], 1) makes stdout (fd=1) a copy of fd[1] (pipe write end) */
                /* After this, writing to stdout will write to the pipe */
                dup2(fd[1], 1);     /* Redirect stdout to write to pipe */
                close(fd[0]);       /* Close read end of pipe (child only writes) */
                close(fd[1]);       /* Close write end after dup2 (stdout is copy now) */
            }

            /* --- 3c: Execute the command --- */
            /* execvp(command_name, argv_array) replaces current process with new program */
            /* cmds[i][0] is the command name (first element of current command's array) */
            /* cmds[i] is the full argv array for the command */
            execvp(cmds[i][0], cmds[i]);

            /* execvp only returns if it fails (e.g., command not found) */
            exit(1);            /* Exit child with error code 1 */
        }

        /* ----- STEP 4: Parent process code (pid > 0) ----- */
        /* Parent continues here after fork (child is running separately) */

        /* --- 4a: Close the input from previous command --- */
        /* Parent doesn't need to read from previous pipe anymore */
        if (in_fd != 0)
            close(in_fd);       /* Close read end from previous iteration */

        /* --- 4b: Prepare for next iteration --- */
        /* If there's a next command, save the read end for it */
        if (cmds[i + 1])
        {
            close(fd[1]);       /* Close write end in parent (only child uses it) */
            in_fd = fd[0];      /* Save read end for next command's input */
        }

        i++;                    /* Move to next command */
    }

    /* ===== FINAL STEP: Wait for all child processes to complete ===== */
    /* wait(&status) waits for any child process to terminate */
    /* Loop continues until wait() returns <= 0 (no more children) */
    int status;
    int result = 0;
    while (wait(&status) > 0)
    {
        /* Check if child exited normally and with non-zero status */
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            result = 1;         /* Mark failure if any child failed */
    }

    return (result);            /* Return 0 on success, 1 if any child failed */
}

/* ************************************************************************** */
/*                              TEST CODE                                     */
/* ************************************************************************** */

// #include <stdio.h>      /* For printf() */

// int main(void)
// {
//     /* Test: Execute "ls | grep picoshell" */
//     /* This is equivalent to running: ls | grep picoshell */
    
//     /* Define first command: ls (list files) */
//     char *cmd1[] = {"ls", NULL};
    
//     /* Define second command: grep picoshell (filter lines containing "picoshell") */
//     char *cmd2[] = {"grep", "picoshell", NULL};
    
//     /* Create array of commands, terminated by NULL */
//     char **cmds[] = {cmd1, cmd2, NULL};

//     printf("Running: ls | grep picoshell\n");
//     printf("Output:\n");
    
//     /* Execute the pipeline */
//     int result = picoshell(cmds);
    
//     printf("\npicoshell returned: %d\n", result);

//     return (result);
// }
