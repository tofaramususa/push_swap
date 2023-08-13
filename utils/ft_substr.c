/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:48:13 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/17 04:12:10 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, int start, size_t len)
{
	char	*substr;
	int		s_len;
	size_t	i;

	s_len = ft_strlen((char *) s);
	if (start + len > (unsigned int) s_len)
		len = s_len - start;
	substr = (char *) malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	if ((int) start > (int) ft_strlen((char *) s))
		return ("\0");
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
