#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static volatile sig_atomic_t g_timeout = 0;
static volatile sig_atomic_t g_childpid = -1;

static void alarm_handler(int sig)
{
	(void)sig;
	g_timeout = 1;
	if (g_childpid > 0)
		kill((pid_t)g_childpid, SIGKILL);
}

int	sandbox(void (*f)(void), unsigned int timeout, int verbose)
{
	struct sigaction	sa;
	pid_t				pid;
	int					status;

	if (!f)
		return (-1);
	g_timeout = 0;
	g_childpid = -1;
	pid = fork();

	if (pid ==0)
	{
		f();
		exit (0);
	}
	g_childpid = pid;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = alarm_handler;
	if (sigaction(SIGALRM, &sa, NULL) == -1)
	{
		kill (pid, SIGKILL);
		waitpid(pid, NULL, 0);
		g_childpid = -1;
		return (-1);
	}
	alarm(timeout);
	if (waitpid(pid, &status, 0) == -1)
	{
		alarm(0);
		g_childpid = -1;
		return (-1);
	}
	alarm(0);
	g_childpid = -1;
	if (g_timeout)
	{
		if (verbose)
			printf("Bad function: timed out after %d seconds\n", timeout);
		return (0);
	}
	if (WIFEXITED(status))
	{
		int code = WEXITSTATUS(status);
		if (code == 0)
		{
			if (verbose)
				printf("Nice function!\n");
			return (1);
		}
		else
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", code);
			return (0);
		}
	}
	if (WIFSIGNALED(status))
	{
		int sig = WTERMSIG(status);
		if (verbose)
			printf("Bad function: %s\n", strsignal(sig));
		return (0);
	}
	return (-1);
}