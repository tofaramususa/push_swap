/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:32:01 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:33:46 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	deletetail(t_node *lst)
{
	t_node	*tail;
	int		data;

	data = 0;
	if (lst == NULL)
		return (-1);
	tail = ft_lstlast(lst);
	if ((*tail).next == NULL)
	{
		(*tail).prev->next = NULL;
		data = (*tail).data;
		free(tail);
	}
	return (data);
}

int	ft_lstsize(t_node *lst)
{
	int		length;
	t_node	*temp;

	temp = lst;
	length = 0;
	while (temp != NULL && temp->next != NULL)
	{
		length++;
		temp = temp->next;
	}
	return (length);
}

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			length;

	length = nbr_len(n);
	if (!length)
		length++;
	str = (char *) malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--length] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
