/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 04:41:36 by tmususa           #+#    #+#             */
/*   Updated: 2023/05/27 03:30:00 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>

typedef struct t_node {
	int				data;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

char	**ft_split(char *s, char seperator);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
void	pa(t_node **A, t_node **B);
void	pb(t_node **A, t_node **B);
void	ra(t_node **A);
void	prepare_to_sort(char **new_args);
void	sa(t_node **A);
void	rra(t_node **A);
void	sort(t_node **A);
int		ft_is_sorted(t_node *head);
int		ft_atoi2(char *str);
int		ft_isdigit(char c);
int		ft_lstsize(t_node *lst);
int		ft_atoi(char *str);
int		deletehead(t_node **lst);
int		deletetail(t_node *lst);
int		check_dup(char *str[]);
char	**ft_clean(char *argv[]);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, size_t len);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_strlen(char *s);
char	*ft_itoa(int n);
int		nbr_len(int n);
void	ft_lstadd_front(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstnew(int content);
void	big_sort(t_node **A, t_node **b);
void	ft_copy(int len, char **new_args, char **copy);
void	create_stack(char **new_args, char **copy, int len);
void	ft_index(int len, char **copy);
int		ft_checkthings(char **argv);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	be_free(t_node **b, t_node **A);
void	free_list(t_node *head);
int		first_check(char **argv);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	sort_three(t_node **A);
void	pick_sorter(t_node **A, t_node **b);
void	sort_four(t_node **A, t_node **b);
void	sort_five(t_node **A, t_node **B);
void	ft_error(char **array);
int		ft_atoi3(char *str);
int		range_from_head(t_node **A, int small);
int		the_smallest(t_node **A);
int		total_bits(t_node **A);
int		ft_breaker(char *str, int index, int sign);
void	free_array(char **array);
int		get_args_length(char *new_args[]);

#endif