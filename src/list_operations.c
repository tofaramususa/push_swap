/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 02:26:27 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/17 04:38:00 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (*lst)
	{
		new->next = *lst;
		new->next->prev = new;
		*lst = new;
	}
	else
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
	}
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*to_last;

	to_last = lst;
	while (to_last != NULL && to_last->next != NULL)
		to_last = to_last->next;
	return (to_last);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*to_last;

	if (*lst)
	{
		to_last = ft_lstlast(*lst);
		to_last->next = new;
		new->prev = to_last;
		new->next = NULL;
	}
	else
		*lst = new;
}

int	deletehead(t_node **lst)
{
	int		data;
	t_node	*temp;

	if (*lst == NULL)
		return (0);
	temp = *lst;
	data = temp->data;
	*lst = temp->next;
	free(temp);
	return (data);
}
