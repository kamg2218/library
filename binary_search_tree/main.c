#include "binary_search_tree.h"

int			main(void)
{
	t_node *head;

	head = NULL;
	printf("empty : %d\n", empty(head));
	insert(&head, create(3));
	insert(&head, create(1));
	insert(&head, create(2));
	printf("retreive : %d\n", retreive(head, 2));
	traverse(head);
	delete(&head, 2);
	printf("retreive : %d\n", retreive(head, 2));
	traverse(head);
	printf("empty : %d\n", empty(head));
	destroy(&head);
	printf("empty : %d\n", empty(head));
	return (0);
}
