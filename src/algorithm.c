/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 02:27:19 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:21:23 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_smallest(t_node **A)
{
	t_node	*temp;
	int		small;

	temp = *A;
	small = temp->data;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if ((temp->data < small))
			small = temp->data;
	}
	return (small);
}

int	range_from_head(t_node **A, int small)
{
	t_node	*temp;
	int		range;

	range = 0;
	temp = *A;
	while (temp)
	{
		if (temp->data == small)
			break ;
		range++;
		temp = temp->next;
	}
	return (range);
}

int	ft_is_sorted(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	total_bits(t_node **A)
{
	t_node	*temp;
	int		max;
	int		total_bits;

	temp = *A;
	max = temp->data;
	total_bits = 0;
	while (temp)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	while ((max >> total_bits) != 0)
		total_bits++;
	return (total_bits);
}

void	free_list(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
