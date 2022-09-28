/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:43:49 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/27 21:21:57 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotate(t_list *a, t_queue n)
{
	int	countr;

	countr = 0;
	if (a)
	{
		while (a)
		{
			if (a->index > n.end || a->index < n.start)
				countr++;
			else
				break ;
			a = a->next;
		}
	}
	return (countr);
}

int	find_min_index(t_list *a)
{
	int	minindex;

	if (a)
	{
		minindex = a->index;
		while (a)
		{
			if (a->index < minindex)
				minindex = a->index;
			a = a->next;
		}
		return (minindex);
	}
	return (0);
}

int	count_ramin(t_list *a)
{
	int	countr;
	int	min;

	countr = 0;
	min = find_min_index(a);
	if (a)
	{
		while (a)
		{
			if (a->index != min)
				countr++;
			else
				break ;
			a = a->next;
		}
	}
	return (countr);
}

t_queue	initialize_tqueue(t_queue que, t_list *a)
{
	size_t	len;
	size_t	n;

	len = ft_lstlen(a);
	if (len > 20 && len <= 100)
		n = len / 5;
	if (len > 100)
		n = len / 8;
	if (len <= 20)
		n = len;
	que.start = 1;
	que.end = n;
	que.section = n;
	que.median = (que.start + que.end) / 2;
	que.range = len;
	return (que);
}
