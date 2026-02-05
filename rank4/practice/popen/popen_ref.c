/* ************************************************************************** */
/*                             MY_POPEN.C                                     */
/*                                                                            */
/*  Standard annotated version of ft_popen - a reimplementation of popen()   */
/*  This function executes a command and returns a file descriptor to read   */
/*  from or write to the command's standard I/O.                              */
/*                                                                            */
/*  Allowed functions: pipe, fork, dup2, execvp, close, exit                  */
/* ************************************************************************** */

#include <unistd.h>     /* pipe(), fork(), dup2(), execvp(), close() */
#include <stdlib.h>     /* exit() */
#include <sys/types.h>  /* pid_t */

/* ========================================================================== */
/*                          MAIN FUNCTION                                     */
/* ========================================================================== */

/*
** ft_popen - Execute a command with a pipe connection
** 
** This function is similar to the standard library's popen(), but returns
** a raw file descriptor instead of a FILE*.
** 
** @param file: The command to execute (can be just name if in PATH)
** @param av: Argument vector for the command (argv format)
** @param type: 'r' to read from command's output, 'w' to write to command's input
** @return: File descriptor on success, -1 on error
** 
** How it works:
** - Creates a pipe for communication
** - Forks a child process
** - Child redirects appropriate end of pipe to stdin/stdout and executes
** - Parent returns the other end of the pipe
** 
** Diagram for type='r' (reading command output):
**    ┌───────────┐         PIPE          ┌───────────┐
**    │   Child   │ stdout ──────────────►│   Parent  │
**    │ (command) │         fd[1]→fd[0]   │ (caller)  │
**    └───────────┘                       └───────────┘
** 
** Diagram for type='w' (writing to command input):
**    ┌───────────┐         PIPE          ┌───────────┐
**    │   Parent  │ ──────────────► stdin │   Child   │
**    │ (caller)  │      fd[1]→fd[0]      │ (command) │
**    └───────────┘                       └───────────┘
*/
int ft_popen(const char *file, char *const av[], char type)
{
    int     fd[2];      /* Pipe file descriptors: fd[0]=read, fd[1]=write */
    pid_t   pid;        /* Process ID from fork() */

    /* ===== VALIDATION ===== */
    /*
    ** Check all parameters:
    ** - file must not be NULL
    ** - av must not be NULL  
    ** - type must be 'r' (read) or 'w' (write)
    ** - pipe() must succeed
    */
    if (!file || !av || (type != 'r' && type != 'w') || pipe(fd) < 0)
        return (-1);    /* Return error if any validation fails */

    /* ===== FORK CHILD PROCESS ===== */
    pid = fork();
    if (pid < 0)        /* Fork failed */
    {
        close(fd[0]);   /* Clean up pipe */
        close(fd[1]);
        return (-1);
    }

    /* ===== CHILD PROCESS ===== */
    if (pid == 0)
    {
        /*
        ** The child will execute the command.
        ** We need to redirect one of its standard file descriptors
        ** to the pipe so it can communicate with the parent.
        **
        ** For type='r' (parent reads, child writes):
        **   Child's stdout (fd 1) → pipe write end (fd[1])
        **   Child closes both pipe ends after dup2
        **
        ** For type='w' (parent writes, child reads):
        **   Child's stdin (fd 0) → pipe read end (fd[0])
        **   Child closes both pipe ends after dup2
        **
        ** The ternary expression:
        **   type == 'r' ? 1 : 0
        **   means: if reading, redirect stdout(1); otherwise redirect stdin(0)
        **
        **   type == 'r' ? fd[1] : fd[0]
        **   means: if reading, use write end; otherwise use read end
        */
        dup2(fd[type == 'r' ? 1 : 0], type == 'r' ? 1 : 0);

        /* Close both pipe ends - we don't need them after dup2 */
        close(fd[0]);
        close(fd[1]);

        /* Execute the command */
        execvp(file, av);

        /* execvp only returns on error */
        exit(1);
    }

    /* ===== PARENT PROCESS ===== */
    /*
    ** Parent needs to return the appropriate end of the pipe.
    **
    ** For type='r' (parent reads from child's output):
    **   Close write end (fd[1]) - parent doesn't write
    **   Return read end (fd[0]) - parent reads from here
    **
    ** For type='w' (parent writes to child's input):
    **   Close read end (fd[0]) - parent doesn't read
    **   Return write end (fd[1]) - parent writes to here
    */
    close(fd[type == 'r' ? 1 : 0]);     /* Close the end we don't need */

    return (fd[type == 'r' ? 0 : 1]);   /* Return the end we do need */
}

/* ========================================================================== */
/*                              TEST CODE                                     */
/* ========================================================================== */

// #include <stdio.h>      /* For printf() - not in allowed functions, just for testing */

// int main(void)
// {
//     int     fd;
//     char    c;

//     printf("=== ft_popen Test ===\n");
//     printf("Running: ls (reading output)\n\n");

//     /* Open "ls" for reading (get its output) */
//     fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
//     if (fd < 0)
//     {
//         printf("ft_popen failed!\n");
//         return (1);
//     }

//     /* Read and print each character from the command's output */
//     while (read(fd, &c, 1) > 0)
//         write(1, &c, 1);

//     /* Clean up */
//     close(fd);

//     return (0);
// }
