#include "binary_search_tree.h"

int				retreive(t_node *head, int content)
{
	t_node		*tmp;

	tmp = head;
	while (tmp)
	{
		if (content == tmp->content)
			return (1);
		else if (content > tmp->content)
			tmp = tmp->right_next;
		else
			tmp = tmp->left_next;
	}
	return (0);
}

/* 
** if the content is string

int			retreive(t_node *head, char *content)
{
	int			cmp;
	t_node		*tmp;

	tmp = head;
	while (tmp)
	{
		cmp = strcmp(new->content, tmp->content);
		if (cmp == 0)
			return (1);
		else if (cmp > 0)
			tmp = tmp->right_next;
		else
			tmp = tmp->left_next;
	}
	return (0);
}
 */
