/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sortcondition.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:37:50 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/28 22:46:59 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_or_pb(t_list **a, t_list **b, t_queue data)
{
	if ((*a)->index >= data.start && (*a)->index <= data.end
		&& (*a)->index != data.range)
	{
		if ((*a)->index == data.range - 1 && (*a)->next->index != data.range
			&& ft_lstlen(*a) < 10)
		{
			ft_swap_ab(*a);
			write(1, "sa\n", 3);
		}
		else
		{
			ft_push_pab(b, a);
			write(1, "pb\n", 3);
		}
	}
}

void	ra_or_rr_or_rra(t_list **a, t_list **b, t_queue data)
{
	int	lstindex;
	int	count_ra;

	lstindex = find_next_index(*a, data);
	count_ra = count_rotate(*a, data);
	while (lstindex != 1 && (int)ft_lstlen(*b) != data.end)
	{
		if (ft_lstlen(*b) > 2 && ((*b)->index < (*b)->next->index
				|| (*b)->index == data.end) && (*b)->index < data.median)
			ft_write_rr(*a, *b);
		else
		{
			if (count_ra > (int)ft_lstlen(*a) / 2)
			{
				ft_reverse_rotate(a, b);
				write(1, "rra\n", 4);
			}
			else
			{
				ft_rotate_lst(*a);
				write(1, "ra\n", 3);
			}
		}
		lstindex--;
	}
}

void	ra_rr_rb(t_list **a, t_list **b, t_queue data)
{
	int	lena;
	int	lenb;

	lena = ft_lstlen(*a);
	lenb = ft_lstlen(*b);
	if (lena > 10 && (!((*a)->index >= data.start && (*a)->index <= data.end)
			|| (*a)->index == data.range) && lenb > 2
		&& (*b)->index < data.median && ((*b)->index < (*b)->next->index))
		ft_write_rr(*a, *b);
	else if ((*a)->index == data.range)
	{
		ft_rotate_lst(*a);
		write(1, "ra\n", 3);
	}
	else if (lena > 10 && lenb > 2 && ((*b)->index < (*b)->next->index)
		&& (*b)->index < data.median)
	{
		ft_rotate_lst(*b);
		write(1, "rb\n", 3);
	}
}

void	push_minindex(t_list **a, t_list **b)
{
	int	minindex;
	int	count_ra;
	int	lena;

	minindex = find_min_index(*a);
	count_ra = count_ramin(*a);
	lena = (int)ft_lstlen(*a);
	while ((*a)->index != minindex)
	{
		if (count_ra < lena / 2 && lena > 3)
		{
			ft_rotate_lst(*a);
			write(1, "ra\n", 3);
		}
		else
		{
			ft_reverse_rotate(a, b);
			write(1, "rra\n", 4);
		}	
	}
	ft_push_pab(b, a);
	write(1, "pb\n", 3);
}
