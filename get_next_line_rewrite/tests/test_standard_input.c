#include <stdio.h>
#include <stdlib.h>
#include "../get_next_line.h"

int main(void)
{
	char *line;

	printf("Enter lines (Ctrl+D to end):\n");
	while ((line = get_next_line(0)) != NULL)
	{
		printf("You typed: %s", line);
		free(line);
	}
	return 0;
}
