/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_find_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:47:55 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/24 20:18:39 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_index(t_list *a, t_queue n)
{
	int	index;

	index = 1;
	while (a)
	{
		if ((a)->index >= n.start && (a)->index <= n.end)
			return (index);
		a = (a)->next;
		index++;
	}
	return (index);
}

int	find_next(t_list *a, int n)
{
	int	index;

	index = 1;
	while (a)
	{
		if ((a)->index == n)
			return (index);
		a = (a)->next;
		index++;
	}
	return (index);
}

int	find_last_index(t_list *a, t_queue n)
{
	int	index;
	int	tmp;

	index = 1;
	tmp = 1;
	while (a)
	{
		if ((a)->index >= n.start && (a)->index <= n.end)
			tmp = index;
		a = (a)->next;
		index++;
	}
	return (tmp);
}

t_list	*ft_find_max(t_list *a, int n)
{
	t_list	*lstmax;
	int		max;

	max = 0;
	lstmax = NULL;
	while (a && n)
	{
		if (a->index > max)
		{
			lstmax = a;
			max = a->index;
		}
		a = a->next;
		n--;
	}
	return (lstmax);
}

int	ft_find_maxn(t_list *a, int n)
{
	int	i;	

	i = 0;
	if (a || n)
	{
		while (a->index != n && i < (int)ft_lstlen(a))
		{
			a = a->next;
			i++;
		}
	}
	return (i);
}
