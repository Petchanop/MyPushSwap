/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:09:17 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/09 19:32:05 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	ft_swap_ab(t_list *lst);
void	ft_swap_bothab(t_list *a, t_list *b);
void	ft_rotate_lst(t_list *a);
void	ft_rotate_all(t_list *a, t_list *b);
t_list  *ft_reverse_rotate(t_list **a);
void	ft_reverse_all(t_list **a, t_list **b);
t_list	*ft_intlst_new(int num);
void	ft_add_lst(t_list **lst, t_list *new);
void	ft_add_lsfront(t_list **lst, t_list *new);
void	ft_dellst(t_list **lst);
void	ft_lstnumclear(t_list **lst);
void	ft_show_ab(t_list *a, t_list *b);
void    push_swap(t_list **a, t_list **b);
int     ft_check_sort(t_list *a, t_list *b);
size_t	ft_lstlen(t_list *lst);
void	ft_push_pab(t_list **a, t_list **b);
t_list	*ft_lstlast(t_list *lst);

#endif
