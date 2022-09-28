/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:24:07 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/28 22:27:51 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_bdata(t_list **b, t_list **maxb, int *lenb, int *lstindex)
{
	*lenb = (int)ft_lstlen(*b);
	*maxb = ft_find_max(*b, ft_lstlen(*b));
	*lstindex = ft_find_maxn(*b, (*maxb)->index);
}

void	sort_maxindex(t_list *a)
{
	t_list	*maxa;
	t_list	*lasta;

	lasta = ft_lstlast(a);
	maxa = ft_find_max(a, ft_lstlen(a));
	if (lasta->index != maxa->index)
	{
		while (lasta->index != maxa->index)
		{
			ft_rotate_lst(a);
			write(1, "ra\n", 3);
			maxa = ft_find_max(a, ft_lstlen(a));
			lasta = ft_lstlast(a);
		}
	}
	if (a->index > a->next->index && ft_lstlen(a) <= 3)
	{
		ft_swap_ab(a);
		write(1, "sa\n", 3);
	}
}

void	pb_sa_sb(t_list **a, t_list **b)
{
	t_list	*maxb;
	int		lstindex;

	maxb = ft_find_max(*b, ft_lstlen(*b));
	lstindex = ft_find_maxn(*b, maxb->index);
	if (ft_check_sort_n(*a, *b, ft_lstlen(*a)) != 1
		&& (*a)->index < maxb->index)
	{
		while ((*a)->index < maxb->index)
		{
			ft_push_pab(b, a);
			write(1, "pb\n", 3);
		}
	}
	if (ft_lstlen(*a) < 10 && ft_lstlen(*a) >= 2
		&& (*a)->index > (*a)->next->index)
	{
		ft_swap_ab(*a);
		write(1, "sa\n", 3);
	}
	if (ft_lstlen(*b) > 1 && (*b)->next->index == (int)ft_lstlen(*b))
	{
		ft_swap_ab(*b);
		write(1, "sb\n", 3);
	}
}

void	pa_sb_or_rb(t_list **a, t_list **b)
{
	int	lenb;

	lenb = (int)ft_lstlen(*b);
	if (ft_check_sort_n(*a, *b, ft_lstlen(*a))
		&& (*b) && (*a)->index == (*b)->index + 1)
	{
		ft_push_pab(a, b);
		write(1, "pa\n", 3);
	}
	else
	{
		if (lenb > 1 && ((*a)->index == (*b)->next->index + 1))
		{
			ft_swap_ab(*b);
			write(1, "sb\n", 3);
		}
		else
		{
			ft_rotate_lst(*b);
			write(1, "rb\n", 3);
		}
	}
}

void	sort_stackb(t_list **a, t_list **b)
{
	int		lenb;
	int		lstindex;
	t_list	*maxb;

	lenb = 0;
	lstindex = 0;
	maxb = NULL;
	initialize_bdata(b, &maxb, &lenb, &lstindex);
	if (lenb >= 3 && (*b)->index != maxb->index)
	{
		while ((lstindex != 1 || (lstindex < lenb && lenb > 2))
			&& (*b)->index != maxb->index && lenb > 1)
		{
			initialize_bdata(b, &maxb, &lenb, &lstindex);
			if (lstindex < lenb / 2)
				pa_sb_or_rb(a, b);
			else if (lenb > 2)
			{
				ft_reverse_rotate(b, a);
				write(1, "rrb\n", 4);
			}
		}
	}
}
