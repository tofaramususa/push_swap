/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:07:13 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:33:58 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(int len, char **copy)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(copy[i]) > ft_atoi(copy[j]))
			{
				temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	create_stack(char **new_args, char **copy, int len)
{
	int		i;
	t_node	**a;

	i = -1;
	a = malloc(sizeof(t_node *));
	*a = NULL;
	ft_copy(len, new_args, copy);
	if (a)
	{
		while (new_args[++i])
			ft_lstadd_back(a, ft_lstnew(ft_atoi(new_args[i])));
		sort(a);
	}
	i = 0;
	while (i < len)
	{
		free(copy[i]);
		free(new_args[i]);
		i++;
	}
	free(new_args);
	free(copy);
	free(a);
}

void	big_sort(t_node **A, t_node **b)
{
	int		bits;
	t_node	*temp;
	int		length;
	int		i;
	int		j;

	i = 0;
	temp = *A;
	length = ft_lstsize(temp) - 1;
	bits = total_bits(A);
	while (i < bits)
	{
		j = -1;
		while (j++ <= length)
		{
			temp = *A;
			if (!(temp->data >> i & 1))
				pb(A, b);
			else
				ra(A);
		}
		while (ft_lstsize(*b) != 0)
			pa(A, b);
		i++;
	}
}

void	prepare_to_sort(char **new_args)
{
	int		i;
	int		len;
	char	**copy;

	len = get_args_length(new_args);
	i = 0;
	copy = malloc((len) * sizeof(char *));
	if (!copy)
	{
		free_array(new_args);
		exit (0);
	}
	while (i < len)
	{
		copy[i] = malloc((ft_strlen(new_args[i]) + 1) * sizeof(char));
		ft_strlcpy(copy[i], new_args[i], ft_strlen(new_args[i]) + 1);
		i++;
	}
	ft_index(len, copy);
	create_stack(new_args, copy, len);
}
