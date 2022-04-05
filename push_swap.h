/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:09:17 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/05 18:45:50 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_slist
{
	struct s_slist		*next;
	struct s_slist		*head;
	struct s_slist		*tail;
	int					num;
}	t_slist;

void	ft_swap_ab(t_slist *lst);
void	ft_swap_bothab(t_slist *a, t_slist *b);
void	ft_rotate_lst(t_slist *a);
void	ft_rotate_all(t_slist *a, t_slist *b);
void	ft_reverse_rotate(t_slist **a);
void	ft_reverse_all(t_slist **a, t_slist **b);
void	*ft_intlst_new(int num);
void	ft_add_slst(t_slist **lst, t_slist *new);
void	ft_add_slsfront(t_slist **lst, t_slist *new);
void	ft_delslst(t_slist **lst);
void	ft_slstclear(t_slist **lst);
void	ft_show_ab(t_slist *a, t_slist *b);
int     ft_check_sort(t_slist *a, t_slist *b);
size_t	ft_slstlen(t_slist *lst);
t_slist	*ft_push_ab(t_slist **a, t_slist *b);
t_slist	*ft_slstlast(t_slist *lst);

#endif
