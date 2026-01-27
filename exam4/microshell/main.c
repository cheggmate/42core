#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/* Helper to write strings to STDERR */
void err(char *str) {
    while (*str)
        write(2, str++, 1);
}

/* Handles the 'cd' builtin */
void cd(char **argv, int i) {
    if (i != 2)
        err("error: cd: bad arguments\n");
    else if (chdir(argv[1]) == -1) {
        err("error: cd: cannot change directory to ");
        err(argv[1]);
        err("\n");
    }
}

/* Executes a command or a pipe sequence */
void exec(char **argv, int i, char **envp) {
    int fd[2];
    int has_pipe = argv[i] && !strcmp(argv[i], "|");

    if (has_pipe && pipe(fd) == -1) {
        err("error: fatal\n");
        exit(1);
    }

    int pid = fork();
    if (pid == 0) {
        argv[i] = NULL;
        if (has_pipe) {
            if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1) {
                err("error: fatal\n");
                exit(1);
            }
        }
        execve(argv[0], argv, envp);
        err("error: cannot execute ");
        err(argv[0]);
        err("\n");
        exit(1);
    }

    if (waitpid(pid, NULL, 0) == -1) {
        err("error: fatal\n");
        exit(1);
    }
    if (has_pipe) {
        if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1) {
            err("error: fatal\n");
            exit(1);
        }
    }
}

int main(int argc, char **argv, char **envp) {
    int i = 0;
    int tmp_fd = dup(0);

    (void)argc;
    while (argv[i] && argv[i + 1]) {
        argv = &argv[i + 1];
        i = 0;
        /* Find the next break point (| or ;) */
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;

        if (strcmp(argv[0], "cd") == 0) {
            cd(argv, i);
        } else if (i != 0) {
            exec(argv, i, envp);
        }
        
        /* If we hit a semicolon or end of input, reset STDIN */
        if (argv[i] && !strcmp(argv[i], ";")) {
            if (dup2(tmp_fd, 0) == -1) {
                err("error: fatal\n");
                exit(1);
            }
        }
    }
    close(tmp_fd);
    return 0;
}