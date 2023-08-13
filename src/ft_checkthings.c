/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkthings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:32:40 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:32:42 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_clean(char *argv[])
{
	char	*arguments;
	char	**new_args;
	int		i;
	char	*temp;

	i = 0;
	while (argv[i])
	{
		if (i == 0)
			arguments = ft_strdup(argv[i]);
		else
		{
			temp = ft_strjoin(arguments, " ");
			free(arguments);
			arguments = ft_strjoin(temp, argv[i]);
			free(temp);
		}
		i++;
	}
	new_args = ft_split(arguments, ' ');
	free(arguments);
	return (new_args);
}

int	ft_checkthings(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi2(argv[i]) == 0)
			return (0);
		i++;
	}
	if (check_dup(argv) == 0)
		return (0);
	return (1);
}

void	ft_error(char **array)
{
	free_array(array);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(0);
}
