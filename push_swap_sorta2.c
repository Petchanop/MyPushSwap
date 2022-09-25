/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorta2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:45:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/25 04:24:01 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb_exit(t_list **a, t_list **b)
{
	if (ft_check_sort_n(*a, *b, ft_lstlen(*a))
		&& (*b) && (*a)->index == (*b)->index + 1)
	{
		ft_push_pab(a, b);
		write(1, "pa\n", 3);
		if (ft_check_sort(*a, *b) == 1)
		{
			ft_lstnumclear(a);
			ft_lstnumclear(b);
			exit(0);
		}
	}
	if (ft_lstlen(*b) > 1 && ft_check_sort_n(*a, *b, ft_lstlen(*a)) != 1
		&& (*a)->index < (*b)->index)
	{
		ft_push_pab(b, a);
		write(1, "pb\n", 3);
	}
}
