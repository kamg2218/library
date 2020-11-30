#include "binary_search_tree.h"

t_node				*create(int content)
{
	t_node			*new;

	if (!(new = (t_node *)malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->content = content;
	new->left_next = NULL;
	new->right_next = NULL;
	new->prev = NULL;
	new->print = 0;
	return (new);
}
