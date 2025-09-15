#include "remove_parentheses.h"

int		min_to_remove(char *str, int s_len)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (++i < s_len)
	{
		if (str[i] == '(')
			count++;
		if (str[i] == ')')
			count--;
	}
	return (count);
}

int	is_in_string(int s_len, char printed[][ s_len - 1], char *str)
{
	int idx;
	idx = 0;
	while (printed[idx][0] != '\0')
	{
		if (strncmp(printed[idx], str, s_len) == 0)
			return (1);
		idx++;
	}
	return (0);
}

void	copy_string(int s_len, char printed[][s_len -1], char *str)
{
	int i;
	i = 0;
	while (printed[i][0])
		i += 1;
	int	k;
	k = 0;
	while (str[k])
	{
		printed[i][k] = str[k];
		k++;
	}
	printed[i][k] = '\0';
}

void	p_str(char *str, int m_remove, int s_len, char printed[][s_len-1], int start)
{
	int i;
	i = -1;

	char s_cpy[99999] = {'\0'};
	while (++i < s_len)
		s_cpy[i] = str[i];
	s_cpy[i] = '\0';
	i = -1;
	while (++i < s_len)
	{
		if (i >= start)
		{
			if (m_remove < 0 && s_cpy[i] == ')')
			{
				s_cpy[i] = ' ';
				m_remove++;
			}
			else if (m_remove > 0 && s_cpy[i] == '(')
			{
				s_cpy[i] = ' ';
				m_remove--;
			}
		}
	}
	// printf("str: %s, m_remove = %d\n", str, m_remove);
	if (m_remove == 0 && is_in_string(s_len, printed, s_cpy) == 0)
	{
		puts(s_cpy);
		copy_string(s_len, printed, s_cpy);
	}
}

void	solve(char *str, int m_remove, int s_len, char printed[][s_len-1], int start)
{
	// printf("check: %d\n", s_len - start < abs(m_remove));
	if (s_len - start < abs(m_remove)   || start == s_len)
		return ;
	p_str(str, m_remove, s_len, printed, start);
	// printf("recurse\n");
	solve(str, m_remove, s_len, printed, start + 1);
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
	// printf("s_len = %d\n", s_len);
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

	if (argc != 2)
	{
		return (0);
	}
	s_len = strlen(argv[1]);
	// printf("s_len = %d\n", s_len);
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
		int	m_remove;

		// printf("last else\n");
		m_remove = min_to_remove(argv[1], s_len);
		if (argv[1][0] == ')')
		{
			argv[1][0] = ' ';
			m_remove++;
		}
		if (argv[1][s_len - 1] == '(')
		{
			argv[1][s_len - 1] = ' ';
			m_remove--;
		}
		
		char	printed[99999][s_len + 1];
		int j;
		j = -1;
		while (++j < 99999)
			printed[j][0] = '\0';
		// printf("min to remove = %d\n\n", m_remove);
		// printf("argv[1] = %s\n", argv[1]);
		solve(argv[1], m_remove, s_len, printed, 0);
		return (0);
	}
}
