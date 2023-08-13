/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:08:15 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:19:57 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **A)
{
	t_node	**b;

	b = malloc(sizeof(t_node *));
	*b = malloc(sizeof(t_node));
	if (*b != NULL)
	{
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	pick_sorter (A, b);
}

void	pick_sorter(t_node **A, t_node **b)
{
	if ((ft_lstsize(*A) + 1) == 2)
		sa(A);
	if ((ft_lstsize(*A) + 1) > 5)
		big_sort(A, b);
	else if ((ft_lstsize(*A) + 1) == 5)
		sort_five(A, b);
	else if ((ft_lstsize(*A) + 1) == 4)
		sort_four(A, b);
	else if ((ft_lstsize(*A) + 1) == 3)
		sort_three(A);
	free_list(*A);
	free_list(*b);
	free(b);
}

void	sort_three(t_node **A)
{
	int	first;
	int	second;
	int	third;

	first = (*A)->data;
	second = (*A)->next->data;
	third = (*A)->next->next->data;
	if (first > second && second < third && first < third)
		sa(A);
	else if (first > second && second > third && first > third)
	{
		sa(A);
		rra(A);
	}	
	else if (first > second && second < third && first > third)
		ra(A);
	else if (first < second && second > third && first < third)
	{
		sa(A);
		ra(A);
	}	
	else if (first < second && second > third && first > third)
		rra(A);
}

void	sort_four(t_node **A, t_node **b)
{
	int	range;

	range = range_from_head(A, the_smallest(A));
	if (range == 3)
		rra(A);
	else if (range == 2)
	{
		rra(A);
		rra(A);
	}
	else if (range == 1)
		ra(A);
	pb(A, b);
	sort_three(A);
	pa(A, b);
}

void	sort_five(t_node **A, t_node **B)
{
	int	range;

	range = range_from_head(A, the_smallest(A));
	if (range == 4)
		rra(A);
	else if (range == 3)
	{
		rra(A);
		rra(A);
	}
	else if (range == 2)
	{
		ra(A);
		ra(A);
	}
	if (range == 1)
		ra(A);
	pb(A, B);
	sort_four(A, B);
	pa(A, B);
}
