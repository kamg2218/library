#include "binary_search_tree.h"

void			destroy(t_node **head)
{
	t_node		*pre;
	t_node		*tmp;

	tmp = *head;
	while (tmp)
	{
		while (tmp->left_next)
			tmp = tmp->left_next;
		while (tmp->right_next)
			tmp = tmp->right_next;
		pre = tmp->prev;
		if (pre && pre->right_next == tmp)
			pre->right_next = NULL;
		else if (pre && pre->left_next == tmp)
			pre->left_next = NULL;
		/*
		 ** if the content is string,
		 free(tmp->content);
		 */
		free(tmp);
		tmp = pre;
	}
	*head = NULL;
}
