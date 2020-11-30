#ifndef		BINARY_SEARCH_TREE_H
# define	BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				print;
	int				content;
	struct s_node	*prev;
	struct s_node	*left_next;
	struct s_node	*right_next;
}					t_node;

t_node			*create(int content);
void			destroy(t_node **head);
void			traverse(t_node *head);
void			insert(t_node **head, t_node *new);
void			delete(t_node **head, int content);
int				empty(t_node *head);
int				retreive(t_node *head, int content);

#endif
