#include "binary_search_tree.h"

static void		move(t_node **head, t_node *tmp)
{
	while (tmp->left_next || tmp->right_next)
	{
		while (tmp->left_next)
		{
			tmp->content = tmp->left_next->content;
			tmp = tmp->left_next;
		}
		if (tmp->right_next)
		{
			tmp->content = tmp->right_next->content;
			tmp = tmp->right_next;
		}
	}
	if (tmp->prev && tmp == tmp->prev->left_next)
		tmp->prev->left_next = NULL;
	else if (tmp->prev && tmp == tmp->prev->right_next)
		tmp->prev->right_next = NULL;
	if (tmp == *head)
		*head = NULL;
	free(tmp);
}

void			delete(t_node **head, int content)
{
	t_node		*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->content == content)
		{
			move(head, tmp);
			return ;
		}
		else if (content > tmp->content)
		{
			if (tmp->right_next == NULL)
				return ;
			tmp = tmp->right_next;
		}
		else
		{
			if (tmp->left_next == NULL)
				return ;
			tmp = tmp->left_next;
		}
	}
}
