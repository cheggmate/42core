#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>


int picoshell(char **cmds[]) {

	int	i = 0;
	int	fd[2];
	int	in_fd = STDIN_FILENO;
	pid_t pid;
	int	status;

	while (cmds[i])
	{
		if (cmds[i+1] != NULL) {
			if (pipe(fd) == -1)
				return (1);
		}
		
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0) {
			if (in_fd != STDIN_FILENO) {
				dup2(in_fd, STDIN_FILENO);
				close(in_fd);
			}
			if (cmds[i + 1] != NULL) {
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			printf("calling execvp\n");
			status = execvp(cmds[i][0], cmds[i]);
			printf("status = %d\n", status);
			if (status == 1)
				exit(1);
		}
		else {
			if (in_fd != STDIN_FILENO)
			{
				close(in_fd);
			}
			if (cmds[i+1] != NULL)
			{
				close(fd[1]);
				in_fd = fd[0];
			}
		}
		
		i++;
	}

	while (i > 0)
	{
		wait(NULL);
		i--;
	}
	return (0);
}
int picoshell(char **cmds[]);
int main(void) {
    printf("--- Starting Picoshell Tests ---\n\n");

    // Test 1: Simple command (ls -la)
    printf("Test 1: Simple Command (ls -la)\n");
    char *cmd1_1[] = {"/bin/ls", "-la", NULL};
    char **test1[] = {cmd1_1, NULL};
    picoshell(test1);
    printf("\n-------------------------------\n");

    // Test 2: Single Pipe (ls | grep "main")
    printf("Test 2: Single Pipe (ls | grep \"main\")\n");
    char *cmd2_1[] = {"/bin/ls", NULL};
    char *cmd2_2[] = {"/usr/bin/grep", "main", NULL};
    char **test2[] = {cmd2_1, cmd2_2, NULL};
    picoshell(test2);
    printf("\n-------------------------------\n");

    // Test 3: Multiple Pipes (ls -l | grep ".c" | wc -l)
    printf("Test 3: Double Pipe (ls -l | grep \".c\" | wc -l)\n");
    char *cmd3_1[] = {"/bin/ls", "-l", NULL};
    char *cmd3_2[] = {"/usr/bin/grep", ".c", NULL};
    char *cmd3_3[] = {"/usr/bin/wc", "-l", NULL};
    char **test3[] = {cmd3_1, cmd3_2, cmd3_3, NULL};
    picoshell(test3);
    printf("\n-------------------------------\n");

	// Test 4: Simple command (echo)
    printf("Test 4: Simple Command (ls -la)\n");
    char *cmd4_1[] = {"echo", "kjsdhfkjsdk.", NULL};
    char **test4[] = {cmd4_1, NULL};
    picoshell(test4);
    printf("\n-------------------------------\n");

    printf("--- Tests Completed ---\n");
    return 0;
}