/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorta2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:45:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/28 23:01:44 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_sort(t_list **a, t_list **b)
{
	if (ft_check_sort(*a, *b) == 1)
	{
		ft_lstnumclear(a);
		ft_lstnumclear(b);
		exit(0);
	}
}

void	pa_pb_exit(t_list **a, t_list **b)
{
	if (ft_check_sort_n(*a, *b, ft_lstlen(*a))
		&& (*b) && (*a)->index == (*b)->index + 1)
	{
		ft_push_pab(a, b);
		write(1, "pa\n", 3);
	}
	if_sort(a, b);
	if (ft_lstlen(*b) > 1 && (*a)->index < (*b)->index
		&& ft_check_sort_n(*a, *b, ft_lstlen(*a)) != 1)
	{
		ft_push_pab(b, a);
		write(1, "pb\n", 3);
	}
}

void	sort_3(t_list **a, t_list **b)
{
	if (ft_lstlen(*a) < 4)
	{
		if ((*a)->index > (*a)->next->index
			&& (*a)->index > (*a)->next->next->index)
		{
			ft_rotate_lst(*a);
			write(1, "ra\n", 3);
		}
		if ((*a)->index > (*a)->next->index)
		{
			ft_swap_ab(*a);
			write(1, "sa\n", 3);
		}
		if ((*a)->next->index > (*a)->next->next->index)
		{
			ft_reverse_rotate(a, b);
			write(1, "rra\n", 4);
		}
	}
}

void	sort_5(t_list **a, t_list **b)
{
	sort_3(a, b);
	while (ft_check_sort(*a, *b) != 2 && ft_lstlen(*a) > 3)
		push_minindex(a, b);
	sort_maxindex(*a);
	if_sort(a, b);
}
