/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 00:19:52 by jotong            #+#    #+#             */
/*   Updated: 2025/09/19 00:19:54 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ----- helpers -----
void free_split(char **arr)
{
    int i = 0;
    if (!arr) return;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

char *find_in_path(char *cmd, char **envp);
char **parse_command(char *arg);

// ----- execute one command -----
void exec_command(char *cmd, char **envp)
{
    char **args = parse_command(cmd);
    if (!args || !args[0])
        exit(1);
    char *cmd_path = find_in_path(args[0], envp);
    if (!cmd_path) {
        fprintf(stderr, "command not found: %s\n", args[0]);
        free_split(args);
        exit(127);
    }
    execve(cmd_path, args, envp);
    perror("execve");
    free(cmd_path);
    free_split(args);
    exit(1);
}

// ----- main pipex logic -----
int main(int argc, char **argv, char **envp)
{
    if (argc < 5) {
        fprintf(stderr, "Usage: %s infile cmd1 ... cmdN outfile\n", argv[0]);
        return 1;
    }

    int infile = open(argv[1], O_RDONLY);
    if (infile < 0) {
        perror(argv[1]);
        return 1;
    }
    int outfile = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile < 0) {
        perror(argv[argc-1]);
        close(infile);
        return 1;
    }

    int prev_fd = infile;  // start with infile as input
    for (int i = 2; i < argc - 1; i++) {
        int pipe_fd[2];
        if (i < argc - 2) { // not the last command → need a pipe
            if (pipe(pipe_fd) == -1) {
                perror("pipe");
                return 1;
            }
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return 1;
        }
        if (pid == 0) {
            // ----- child -----
            dup2(prev_fd, STDIN_FILENO);
            if (i == argc - 2) {
                dup2(outfile, STDOUT_FILENO); // last command → outfile
            } else {
                dup2(pipe_fd[1], STDOUT_FILENO); // write to next pipe
            }
            if (prev_fd != infile) close(prev_fd);
            if (i < argc - 2) {
                close(pipe_fd[0]);
                close(pipe_fd[1]);
            }
            exec_command(argv[i], envp);
        }
        // ----- parent -----
        if (prev_fd != infile) close(prev_fd); // close old input
        if (i < argc - 2) {
            close(pipe_fd[1]);      // parent keeps only read end
            prev_fd = pipe_fd[0];   // next command will read here
        }
    }

    close(infile);
    close(outfile);
    while (wait(NULL) > 0); // wait for all children
    return 0;
}
