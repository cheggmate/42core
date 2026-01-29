#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void ft_putstr_fd(char *str, int fd)
{
    while (*str)
        write(fd, str++, 1);
}

void fatal_error(void)
{
    ft_putstr_fd("error: fatal\n", 2);
    exit(1);
}

void exec_error(char *cmd)
{
    ft_putstr_fd("error: cannot execute ", 2);
    ft_putstr_fd(cmd, 2);
    ft_putstr_fd("\n", 2);
}

void cd_error(char *path)
{
    ft_putstr_fd("error: cd: cannot change directory to ", 2);
    ft_putstr_fd(path, 2);
    ft_putstr_fd("\n", 2);
}

int is_separator(char *str, char *sep)
{
    return (str && strcmp(str, sep) == 0);
}

int count_args(char **argv, int start)
{
    int count = 0;
    while (argv[start + count] && !is_separator(argv[start + count], "|") 
           && !is_separator(argv[start + count], ";"))
        count++;
    return count;
}

void execute_cd(char **argv, int i)
{
    if (count_args(argv, i) != 2)
    {
        ft_putstr_fd("error: cd: bad arguments\n", 2);
        return;
    }
    if (chdir(argv[i + 1]) != 0)
        cd_error(argv[i + 1]);
}

void execute_command(char **argv, int i, char **env)
{
    int argc = count_args(argv, i);
    char **cmd = malloc(sizeof(char *) * (argc + 1));
    if (!cmd)
        fatal_error();
    
    for (int j = 0; j < argc; j++)
        cmd[j] = argv[i + j];
    cmd[argc] = NULL;
    
    execve(cmd[0], cmd, env);
    exec_error(cmd[0]);
    free(cmd);
    exit(1);
}

void exec_pipeline(char **argv, int start, int end, char **env)
{
    int pipe_count = 0;
    int i = start;
    
    // Count pipes
    while (i < end)
    {
        if (is_separator(argv[i], "|"))
            pipe_count++;
        i++;
    }
    
    if (pipe_count == 0)
    {
        // Single command
        if (strcmp(argv[start], "cd") == 0)
        {
            execute_cd(argv, start);
            return;
        }
        
        pid_t pid = fork();
        if (pid < 0)
            fatal_error();
        
        if (pid == 0)
            execute_command(argv, start, env);
        
        waitpid(pid, NULL, 0);
        return;
    }
    
    // Multiple commands with pipes
    int **pipes = malloc(sizeof(int *) * pipe_count);
    if (!pipes)
        fatal_error();
    
    for (int j = 0; j < pipe_count; j++)
    {
        pipes[j] = malloc(sizeof(int) * 2);
        if (!pipes[j] || pipe(pipes[j]) < 0)
            fatal_error();
    }
    
    int cmd_idx = 0;
    i = start;
    
    while (i < end)
    {
        int cmd_start = i;
        while (i < end && !is_separator(argv[i], "|"))
            i++;
        
        pid_t pid = fork();
        if (pid < 0)
            fatal_error();
        
        if (pid == 0)
        {
            // Redirect input from previous pipe
            if (cmd_idx > 0)
            {
                if (dup2(pipes[cmd_idx - 1][0], 0) < 0)
                    fatal_error();
            }
            
            // Redirect output to next pipe
            if (cmd_idx < pipe_count)
            {
                if (dup2(pipes[cmd_idx][1], 1) < 0)
                    fatal_error();
            }
            
            // Close all pipe fds
            for (int j = 0; j < pipe_count; j++)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }
            
            execute_command(argv, cmd_start, env);
        }
        
        cmd_idx++;
        if (i < end)
            i++; // Skip the "|"
    }
    
    // Close all pipe fds in parent
    for (int j = 0; j < pipe_count; j++)
    {
        close(pipes[j][0]);
        close(pipes[j][1]);
    }
    
    // Wait for all children
    for (int j = 0; j <= pipe_count; j++)
        waitpid(-1, NULL, 0);
    
    // Free pipes
    for (int j = 0; j < pipe_count; j++)
        free(pipes[j]);
    free(pipes);
}

int main(int argc, char **argv, char **env)
{
    if (argc < 2)
        return 0;
    
    int i = 1;
    
    while (i < argc)
    {
        int start = i;
        
        // Find the end of this pipeline (terminated by ";" or end of args)
        while (i < argc && !is_separator(argv[i], ";"))
            i++;
        
        if (i > start)
            exec_pipeline(argv, start, i, env);
        
        if (i < argc)
            i++; // Skip the ";"
    }
    
    return 0;
}