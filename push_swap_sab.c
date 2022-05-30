/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:13:54 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/05 17:07:08 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_lstlen(t_list *lst);

void	ft_swap_ab(t_list *lst)
{
	t_list	*tm1;
	t_list	*tm2;
	int		tmp;
	int		index;

	if (ft_lstlen(lst) > 1)
	{
		tm1 = lst;
		tm2 = lst->next;
		tmp = tm1->content;
		index = tm1->index;
		tm1->content = tm2->content;
		tm1->index = tm2->index;
		tm2->content = tmp;
		tm2->index = index;
	}
}

void	ft_swap_bothab(t_list *a, t_list *b)
{
	ft_swap_ab(a);
	ft_swap_ab(b);
}
