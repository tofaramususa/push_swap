/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:11:57 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:34:29 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_len(int n)
{
	int	len;

	if (n <= -2147483648)
	{
		len = 11;
		return (len);
	}
	len = 0;
	if (n < 0)
	{
			n *= -1;
			len += 1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_copy(int len, char **new_args, char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (ft_atoi(new_args[i]) == ft_atoi(copy[j]))
			{
				free(new_args[i]);
				new_args[i] = ft_itoa(j);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	check_dup(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) - ft_atoi(str[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
