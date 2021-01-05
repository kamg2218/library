#include "binary_search_tree.h"

static t_node	*tmp_right_next(t_node *tmp)
{
	t_node		*new;
	t_node		*old;
	t_node		*tail;

	new = tmp->right_next;
	old = new;
	while (new->left_next)
		new = new->left_next;
	if (new != old)
	{
		old = new->prev;
		new->prev = NULL;
		while (old != tmp)
		{
			tail = new;
			while (tail->right_next)
				tail = tail->right_next;
			old->left_next = NULL;
			tail->right_next = old;
			old = old->prev;
			tail->right_next->prev = tail;
		}
		if (tmp->prev == NULL)
			new->prev = NULL;
		else
			new->prev = tmp->prev;
	}
	return (new);
}

static void		move(t_node **head, t_node *tmp)
{
	t_node		*new;

	new = NULL;
	while (tmp->left_next || tmp->right_next)
	{
		while (tmp->left_next)
		{
			tmp->content = tmp->left_next->content;
			tmp = tmp->left_next;
		}
		if (tmp->right_next)
		{
			new = tmp_right_next(tmp);
			break ;
		}
	}
	if (tmp->prev && tmp == tmp->prev->left_next)
		tmp->prev->left_next = new;
	else if (tmp->prev && tmp == tmp->prev->right_next)
		tmp->prev->right_next = new;
	if (tmp == *head)
		*head = new;
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
