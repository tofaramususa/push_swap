/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:36:52 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:20:37 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_atoi(char *str)
{
	int			i;
	long		rs;
	int			sg;	

	i = 0;
	rs = 0;
	sg = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sg = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		rs = rs * 10 + str[i] - '0';
		if (rs * sg > INT_MAX)
			return (0);
		else if (rs * sg < INT_MIN)
			return (0);
		i++;
	}
	return (rs * sg);
}

int	ft_atoi2(char *str)
{
	int			i;
	int			sg;	

	i = 0;
	sg = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sg = -1;
		i++;
	}
	if (str[i] == '\0' || ft_breaker(str, i, sg) == 0)
		return (0);
	return (1);
}

int	ft_breaker(char *str, int index, int sign)
{
	long	rs;

	rs = 0;
	while (str[index] != '\0')
	{
		if (!(ft_isdigit(str[index])))
			return (0);
		rs = rs * 10 + str[index] - '0';
		if (rs * sign > INT_MAX || rs * sign < INT_MIN)
			return (0);
		index++;
	}
	return (1);
}

int	ft_atoi3(char *str)
{
	int			i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	return (1);
}
