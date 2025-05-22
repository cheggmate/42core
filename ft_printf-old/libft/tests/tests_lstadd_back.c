#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_lstadd_back_bonus.c"

int main(void)
{
	// Test 1: add to an empty list;
	t_list *list1 = NULL;
	t_list *node1 = ft_lstnew("first");
	printf("created list 1\n");

	ft_lstadd_back(&list1, node1);
	printf("added new to list 1\n");

	assert(list1 == node1);
	assert(list1->next == NULL);
	printf("Test 1 passed: add to empty list\n");
	free(list1);

	// Test 2: add to a list with one node
	t_list *list2 = ft_lstnew("first");
	t_list *node2 = ft_lstnew("second");

	ft_lstadd_back(&list2, node2);
	assert(list2->next == node2);
	assert(list2->next->next == NULL);
	printf("Test 2 passed: add to list with one node\n");
	free(list2);
	free(node2);

	// Test 3: add multiple nodes
	t_list *list3 = ft_lstnew("first");
	t_list *node3_a = ft_lstnew("second");
	t_list *node3_b = ft_lstnew("third");
	t_list *node3_c = ft_lstnew("fourth");
	ft_lstadd_back(&list3, node3_a);
	ft_lstadd_back(&list3, node3_b);
	ft_lstadd_back(&list3, node3_c);
	assert(strcmp((list3->next)->content, "second") == 0);
	assert(strcmp(((list3->next)->next)->content, "third") == 0);
	assert(strcmp((((list3->next)->next)->next)->content, "fourth") == 0);
	printf("Test 4 passed\n");
	free(node3_c);
	free(node3_b);
	free(node3_a);
	free(list3);


	printf("All tests passed!\n");
    return 0;
}