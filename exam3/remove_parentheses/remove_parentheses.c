#include "remove_parentheses.h"

void	solve(char *str)
{
	int i;
	int	p_open;
	int p_close;
	int s_len;
	int	d_len;
	int y;
	char *dest;
	char *final;

	i = -1;
	p_open = 0;
	y = 0;
	s_len = strlen(str);
	dest = malloc(s_len + 1);
	if (!dest)
		return ;
	dest[s_len] = '\0';
	while (++i < s_len)
	{
		if (str[i] == '(')
		{
			dest[y] = str[i];
			y++;
			p_open++;
		}
		else if (str[i] == ')')
		{
			if (p_open > 0)
			{
				p_open--;
				dest[y] = str[i];
				y++;
			}
		}
		else
		{
			dest[y] = str[i];
			y++;
		}
	}
	dest[y] = '\0';
	d_len = y;
	i = d_len;
	p_close = 0;
	y = d_len - 1;
	final = malloc(d_len + 1);
	if (!final)
		return ;
	final[d_len] = '\0';
	while(--i >= 0)
	{
		if (dest[i] == ')')
		{
			p_close++;
			final[y] = dest[i];
			y--; 
		}
		else if (dest[i] == '(')
		{
			if (p_close > 0)
			{
				p_close--;
				final[y] = dest[i];
				y--;
			}
		}
		else
		{
			final[y] = dest[i];
			y--;
		}
	}
	write(1, "\"", 1);
	while (++y < d_len)
	{
		write(1, &final[y], 1);
	}
	write(1, "\"\n", 2);
	free(str);
	free(dest);
	free(final);
}


int	is_special_case(char *str)
{
	int i;
	int	s_len;
	int	count;
	int count_l;

	i = -1;
	count = 0;
	count_l = 0;
	s_len = strlen(str);
	if (str[0] == ')' && str[1] == '(' && strlen(str) == 2)
		return (1);
	else
	{
		while(++i < s_len)
		{
			if (str[i] == ')')
				count++;
			else if (str[i] == '(')
				count_l++;
		}
		if (count == s_len || count_l == s_len)
			return (2);
		else if (count == 0 && count_l == 0)
			return (3);

	}
	return (0);
}

int	main(int argc, char **argv)
{
	// char 	*str;
	int 	s_len;
	char	*cleaned;

	if (argc != 2)
	{
		return (0);
	}
	s_len = strlen(argv[1]);
	if (s_len == 0)
	{
		write(1, "\"\"\n", 3);
		return (0);
	}
	else if (is_special_case(argv[1]) == 1 || is_special_case(argv[1]) == 2)
	{
		write (1, "\"\"\n", 3);
		return (0);
	}
	else if (is_special_case(argv[1]) == 3)
	{
		write(1, "\"", 1);
		write(1, argv[1], s_len);
		write(1, "\"\n", 2);
	} 
	else
	{
		cleaned = malloc((s_len + 1));
		if (!cleaned)
			return(0);
		int i;
		i = -1;
		while (++i < s_len)
			cleaned[i] = argv[1][i];
		// printf("cleaned = %s\n", cleaned);
		solve(cleaned);
		// free(cleaned);
		return (0);
	}
}
