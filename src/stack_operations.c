/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 02:28:59 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:33:12 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **A, t_node **B)
{
	int		data;
	t_node	*new_node;

	data = deletehead(B);
	new_node = ft_lstnew(data);
	ft_lstadd_front(A, new_node);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **A, t_node **B)
{
	int		data;
	t_node	*new_node;

	data = deletehead(A);
	new_node = ft_lstnew(data);
	ft_lstadd_front(B, new_node);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_node **A)
{
	int		data;
	t_node	*new_node;

	data = deletehead(A);
	new_node = ft_lstnew(data);
	ft_lstadd_back(A, new_node);
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_node **A)
{
	int		data;
	t_node	*new_node;

	data = deletetail(*A);
	new_node = ft_lstnew(data);
	ft_lstadd_front(A, new_node);
	ft_putstr_fd("rra\n", 1);
}

void	sa(t_node **A)
{
	int		old_head;
	int		new_head1;
	t_node	*new_head;
	t_node	*new_next;

	old_head = deletehead(A);
	new_head1 = deletehead(A);
	new_next = ft_lstnew(old_head);
	new_head = ft_lstnew(new_head1);
	ft_lstadd_front(A, new_next);
	ft_lstadd_front(A, new_head);
	ft_putstr_fd("sa\n", 1);
}
