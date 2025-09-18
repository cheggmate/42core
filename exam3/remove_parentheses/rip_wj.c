#include <stdio.h>

int	check_brackets(char *str)
{
	int	count = 0;
	while (*str)
	{
		if (*str == '(')
			count++;
		if (*str == ')')
			count--;
		if (count < 0)
			return (0);
		str++;
	}
	if (count != 0)
		return (0);
	return 1;
}

int	recurse(char *head, char *str, int min, int count)
{
	char		temp;
	static int	print = 0;
	
	if (count > min)
		return (0);
	for (int i = 0; str[i]; i++)
	{
		temp = str[i];
		str[i] = ' ';
		recurse(head, str + i + 1, min, count + 1);
		if (check_brackets(head))
		{
			print = count;
			puts(head);
		}
		str[i] = temp;
	}
	return (print);
}

#include <string.h>
int main (int ac, char **av)
{
	if (ac != 2)
		return 1;
	if(!*av[1])
	{
		puts("");
		return (0);
	}
	if (check_brackets(av[1]))
	{
		puts(av[1]);
		return (0);
	}
	puts("input:"); puts(av[1]); puts("");
	for (int i = 0; av[1][i]; i++)
	{
		if (recurse(av[1], av[1], i, 1))
			return (0);
	}
}