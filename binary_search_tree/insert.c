#include "binary_search_tree.h"

void			insert(t_node **head, t_node *new)
{
	t_node		*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = new;
		return ;
	}
	while (tmp)
	{
		if (new->content > tmp->content)
		{
			if (tmp->right_next == NULL)
				break ;
			tmp = tmp->right_next;
		}
		else
		{
			if (tmp->left_next == NULL)
				break ;
			tmp = tmp->left_next;
		}
	}
	if (new->content > tmp->content)
		tmp->right_next = new;
	else
		tmp->left_next = new;
	new->prev = tmp;
}

/*
 ** if the content is string

	if (strcmp(new->content, tmp->content) > 0)

 */
