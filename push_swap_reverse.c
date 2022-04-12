/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:52:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/09 19:18:31 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_intlst_new(int num);

t_list	*ft_lstlast(t_list *lst);

size_t	ft_lstlen(t_list *lst);

void	ft_dellst(t_list **lst);

void	ft_add_lstfront(t_list **lst, t_list *new);

void	ft_reverse_rotate(t_list **a)
{
	t_list	*re;
	t_list	*del;
	t_list	*tmp;

	re = NULL;
	tmp = NULL;
	if (a)
	{
		del = ft_lstlast(*a);
		re = ft_intlst_new(del->content);
		ft_add_lstfront(a, re);
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		free(tmp->next);
	}
}

void	ft_reverse_all(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
