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

size_t	ft_slstlen(t_slist *lst);

void	ft_swap_ab(t_slist *lst)
{
	t_slist	*tm1;
	t_slist	*tm2;
	int		tmp;

	if (ft_slstlen(lst) > 1)
	{
		tm1 = lst;
		tm2 = lst->next;
		if (tm1->num > tm2->num)
		{
			tmp = tm1->num;
			tm1->num = tm2->num;
			tm2->num = tmp;
		}
	}
}

void	ft_swap_bothab(t_slist *a, t_slist *b)
{
	ft_swap_ab(a);
	ft_swap_ab(b);
}
