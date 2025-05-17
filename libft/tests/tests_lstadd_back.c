#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include "../ft_lstadd_back_bonus.c"

int main(void)
{
	// Test 1: add to an empty list;
	t_list *list = NULL;
	t_list *node = ft_lstnew("first");

	ft_lstadd_back(&list, node);
	assert(list == node);
	assert(list->next == NULL);
	printf("Test 1 passed: add to empty list\n");

	// Test 2: add to a list with one node:
	t_list *list = ft_lstnew("first");
	t_list *node = ft_lstnew("second");

	ft_lstadd_back(&list, node);
	assert(list->next == node);
	assert(list->next->next == NULL);
	printf("Test 2 passed: add to list with one node\n");


	printf("All tests passed!\n");
    return 0;
}