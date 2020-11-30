#include "binary_search_tree.h"

void		traverse(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		while (tmp->left_next && !(tmp->left_next->print))
			tmp = tmp->left_next;
		if (tmp->print && tmp->right_next && !tmp->right_next->print)
				tmp = tmp->right_next;
		if (tmp->print == 0)
		{
			printf("%d\n", tmp->content);
			tmp->print = 1;
		}
		/*
		  ** if the content is string
		
		  if (tmp->print == 0)
		  {
		  	printf("%s\n", tmp->content);
			tmp->print = 1;
		  }

		 */
		if (tmp->prev == NULL
				&& ((tmp->right_next && tmp->right_next->print)
					|| !(tmp->right_next)))
			return ;
		if (tmp->prev && tmp->right_next == NULL)
			tmp = tmp->prev;
		else if (tmp->right_next && !tmp->right_next->print)
			tmp = tmp->right_next;
		if (tmp->print)
		{
			while (tmp->prev && tmp->print)
				tmp = tmp->prev;
		}
	}
}
