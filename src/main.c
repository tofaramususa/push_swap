/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:15:57 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:30:00 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_args_length(char *new_args[])
{
	int	length;

	length = 0;
	while (new_args[length] != NULL)
		length++;
	return (length);
}

int	first_check(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (argv[i])
	{
		j = 0;
		len = ft_strlen(argv[i]);
		if (argv[i][0] == '\0')
			return (0);
		while ((argv[i][j] == '-' || argv[i][j] == '+' || argv[i][j] == 32
			|| (argv[i][j] >= 9 && argv[i][j] <= 13)))
				j++;
		if (j == len)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_int_sorted(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
				return (0);
			j++;
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char	**new_args;

	if (argc == 1)
		exit (0);
	++argv;
	if (argc == 2 && ft_atoi3(argv[0]) == 0)
		ft_error(NULL);
	if (first_check(argv) == 0)
		ft_error(NULL);
	new_args = ft_clean(argv);
	if (ft_checkthings(new_args) == 0)
		ft_error(new_args);
	if (ft_is_int_sorted(new_args))
	{
		free_array(new_args);
		exit(0);
	}
	prepare_to_sort(new_args);
	return (0);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
			free(array[i++]);
		free(array);
	}
}
