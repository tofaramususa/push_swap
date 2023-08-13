/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:35:57 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/26 22:58:47 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_words(const char *s, char seperator)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != seperator)
		{
			count++;
			while (s[i] && s[i] != seperator)
					i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char seperator)
{
	char	**array;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	array = (char **) malloc(sizeof(char *) * (num_words(s, seperator) + 1));
	if (array == NULL)
		return (NULL);
	while (i < num_words(s, seperator))
	{
		while (s[start] == seperator)
			start++;
		end = start;
		while (s[end] != seperator && s[end])
			end++;
		array[i++] = ft_substr(s, start, end - start);
		start = end;
	}
	array[i] = NULL;
	return (array);
}
