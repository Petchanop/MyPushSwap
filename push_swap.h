/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:09:17 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/25 22:25:22 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "limits.h"

typedef struct s_list
{
	struct s_list		*next;
	long				content;
	int					index;
}	t_list;

typedef struct s_queue
{
	int	start;
	int	end;
	int	median;
	int	range;
	int	section;
}	t_queue;

void	ft_swap_ab(t_list *lst);
void	ft_swap_bothab(t_list *a, t_list *b);
void	ft_rotate_lst(t_list *a);
void	ft_rotate_all(t_list *a, t_list *b);
void	ft_reverse_rotate(t_list **a);
void	ft_reverse_all(t_list **a, t_list **b);
void	ft_add_lst(t_list **lst, t_list *new);
void	ft_add_lsfront(t_list **lst, t_list *new);
void	ft_lstnumclear(t_list **lst);
void	ft_show_ab(t_list *a, t_list *b);
void	ft_push_pab(t_list **a, t_list **b);
void	push_swap(t_list **a, t_list **b, t_queue min);
void	create_stack_a(char **split, char *num, t_list **lst, int i);
void	format_input(char **input, int argc, t_list **lst);
void	add_index(t_list **stack_a);
void	check_empty(char **argv);
void	sa_or_pb(t_list **a, t_list **b, t_queue data);
void	ra_or_rr_or_rra(t_list **a, t_list **b, t_queue data);
void	ra_rr_rb(t_list **a, t_list **b, t_queue data);
void	push_minindex(t_list **a, t_list **b);
void	sort_maxindex(t_list *a);
void	pb_sa_sb(t_list **a, t_list **b);
void	sort_stackb(t_list **a, t_list **b);
void	pa_pb_exit(t_list **a, t_list **b);
int		check_digit(char *num);
int		check_double(t_list *lst1, t_list *lst2);
int		check_input(t_list *lst);
int		count_rotate(t_list *a, t_queue n);
int		count_ramin(t_list *a);
int		ft_check_sort(t_list *a, t_list *b);
int		ft_check_sort_n(t_list *a, t_list *b, int n);
int		ft_check_sortb(t_list *a, int n);
int		ft_find_maxn(t_list *a, int n);
int		ft_check_sortn(t_list *a, int len);
int		ft_isdigit(int c);
int		ft_count_compare(t_list *a, t_list *a1, int n);
int		find_next_index(t_list *a, t_queue n);
int		find_next(t_list *a, int n);
int		find_last_index(t_list *a, t_queue n);
int		find_min_index(t_list *a);
long	ft_atoi(char const *num);
char	**ft_split(char const *s, char c);
size_t	ft_lstlen(t_list *lst);
t_list	*ft_intlst_new(long num, int index);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_find_lstat(t_list *lst, int n);
t_list	*ft_find_lst(t_list *lst);
t_list	*ft_find_max(t_list *a, int n);

#endif
