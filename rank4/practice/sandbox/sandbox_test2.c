#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

static volatile sig_atomic_t g_timeout = 0;
static volatile sig_atomic_t g_childpid = -1;

static void	alarm_handler(int sig)
{
	(void)sig;
	g_timeout = 1;
	if (g_childpid > 0)
		kill((pid_t)g_childpid, SIGKILL);
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	int status;
	struct sigaction sa;
	pid_t pid;

	if (!f)
		return (-1);
	pid = fork();
	g_childpid = -1;
	g_timeout = 0;
	if (pid == -1)
	{
		g_timeout = 1;
		return -1;
	}
	if (pid == 0)
	{
		f();
		exit(0);
	}
	g_childpid = pid;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = alarm_handler;
	
	alarm(timeout);
	if (waitpid(pid, &status, 0) == -1)
	{
		g_timeout = 1;
		return -1;
	}
	if (g_timeout)
	{
		if (verbose)
			printf("Bad function: timed out after %d seconds\n", timeout);
		return -1;
	}
	if (WIFEXITED(status))
	{
		int code = WEXITSTATUS(status);
		if (code == 0)
		{
			if (verbose)
				printf("Nice function!\n");
			return 1;
		}
		else
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", code);
			return 0;
		}
	}
	if (WIFSIGNALED(status))
	{
		int sig = WTERMSIG(status);
		if (verbose)
			printf("Bad function: %s\n", strsignal(sig));
		return 0;
	}
	if (WIFSTOPPED(status))
	{
		kill(pid, SIGKILL);
		waitpid(pid, &status, 0);
		if (verbose)
			printf("Bad function: %s\n", strsignal(SIGSTOP));
		return 0;
	}
	return -1;
}