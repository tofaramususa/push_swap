/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:14:23 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/10 15:10:13 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*s12;

	s1_len = ft_strlen((char *) s1);
	s2_len = ft_strlen((char *) s2);
	s12 = (char *) malloc(s2_len + s1_len + 1);
	if (s12 == NULL)
		return (NULL);
	ft_memcpy(s12, s1, s1_len);
	ft_memcpy(s12 + s1_len, s2, s2_len);
	s12[s2_len + s1_len] = '\0';
	return (s12);
}
