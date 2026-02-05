#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int sandbox(void (*f)(void), unsigned int timeout, bool verbose);

void nice_function(void)
{
    // Esta función no hace nada malo
    return;
}

void bad_function_exit_code(void)
{
    // Esta función termina con código de error
    exit(1);
}

void bad_function_segfault(void)
{
    // Esta función causa segmentation fault
    int *ptr = NULL;
    *ptr = 42;
}

void bad_function_timeout(void)
{
    // Esta función nunca termina
    while (1) {}
}

void bad_function_abort(void)
{
    // Esta función llama abort()
    abort();
}
 
void ok_f(void)
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

void stop_f(void)
{
    raise(SIGSTOP);
    sleep(10);
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

int main()
{
    int result;

    printf("Testing nice function:\n");
    result = sandbox(nice_function, 5, true);
    printf("Result: %d\n\n", result);  // Esperado: 1

    printf("Testing bad function (segfault):\n");
    result = sandbox(bad_function_segfault, 5, true);
    printf("Result: %d\n\n", result);  // Esperado: 0

    printf("Testing bad function (timeout):\n");
    result = sandbox(bad_function_timeout, 2, true);
    printf("Result: %d\n\n", result);  // Esperado: 0

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
}
 
