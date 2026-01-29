#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char **cmds[]) {
    int i = 0;
    int pipe_fds[2];
    int prev_fd = STDIN_FILENO; // Start reading from STDIN
    pid_t pid;

    while (cmds[i] != NULL) {
        // Create a pipe unless it's the very last command
        if (cmds[i + 1] != NULL) {
            if (pipe(pipe_fds) == -1)
                return 1;
        }

        pid = fork();
        if (pid == -1)
            return 1;

        if (pid == 0) {
            // 1. Redirect input from the previous command's pipe
            if (prev_fd != STDIN_FILENO) {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }

            // 2. Redirect output to the current pipe (if not the last command)
            if (cmds[i + 1] != NULL) {
                dup2(pipe_fds[1], STDOUT_FILENO);
                close(pipe_fds[0]);
                close(pipe_fds[1]);
            }

            // 3. Execute the command
            // cmds[i] is a char**, e.g., {"/bin/ls", "-l", NULL}
            execvp(cmds[i][0], cmds[i]);
            exit(1); // Exit if exec fails
        } else {
            // Parent process cleanup
            if (prev_fd != STDIN_FILENO)
                close(prev_fd);
            
            if (cmds[i + 1] != NULL) {
                close(pipe_fds[1]);
                prev_fd = pipe_fds[0]; // Save the read end for the next child
            }
            i++;
        }
    }

    // Wait for all children to finish
    while (i > 0) {
        wait(NULL);
        i--;
    }
    return 0;
}

int main(void) {
    // Example of how the 3D array is structured for the exam:
    // This represents: ls -l | grep "txt" | wc -l
    // char *cmd1[] = {"ls", "-l", NULL};
    // char *cmd2[] = {"grep", "txt", NULL};
    // char *cmd3[] = {"wc", "-l", NULL};

	char *cmd1[] = {"echo", "sdfsdkhfj world.", NULL};
    char *cmd2[] = {"grep", "world", NULL};
    char *cmd3[] = {"wc", "-w", NULL};
    
    char **cmds[] = {cmd1, cmd2, cmd3, NULL};

    return picoshell(cmds);
}