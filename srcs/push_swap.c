/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:28:22 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/28 22:42:20 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arrange_stack(t_list **a, t_list **b, t_queue len)
{
	int	lena;
	int	lenb;

	lena = (int)ft_lstlen(*a);
	lenb = (int)ft_lstlen(*b);
	while (!ft_check_sortb(*b, len.end) && lenb != len.end && lena > 5)
	{
		sa_or_pb(a, b, len);
		ra_or_rr_or_rra(a, b, len);
		ra_rr_rb(a, b, len);
		lena = (int)ft_lstlen(*a);
		if (lena - 10 < len.section)
				len.section = lena / 2;
		if ((int)ft_lstlen(*b) == len.end)
		{
			len.start = len.end + 1;
			len.end += len.section;
			len.median = (len.end + len.start) / 2;
		}
		if (lena < len.section && lena <= 20)
			push_minindex(a, b);
	}
	return ;
}

void	sort_stack_a(t_list **a, t_list **b)
{
	while (ft_check_sort(*a, *b) != 1)
	{
		if (!ft_check_sort_n(*a, *b, ft_lstlen(*a)) && ft_lstlen(*a) > 2)
			sort_5(a, b);
		sort_maxindex(*a);
		if (*b)
		{
			pb_sa_sb(a, b);
			sort_stackb(a, b);
		}
		pa_pb_exit(a, b);
	}
	return ;
}

void	push_swap(t_list **a, t_list **b, t_queue len)
{
	int	n;

	n = len.section;
	while (ft_check_sort(*a, *b) != 1)
	{
		if ((int)ft_lstlen(*a) > len.section)
			arrange_stack(a, b, len);
		else if ((int)ft_lstlen(*a) <= n && (int)ft_lstlen(*a) > 5)
		{
			if (len.end == len.range)
				len.end--;
			arrange_stack(a, b, len);
			continue ;
		}
		else
		{
			sort_stack_a(a, b);
			exit(0);
		}
	}
	return ;
}
