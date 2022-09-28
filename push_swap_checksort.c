/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:13:04 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/28 23:49:37 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort_n(t_list *a, t_list *b, int n)
{
	int	count;
	int	len;

	count = 0;
	len = ft_lstlen(a);
	if (len == 1)
		return (2);
	if (len > 1)
	{
		while (a->next && n > 0)
		{
			if (a->content <= a->next->content && a->next)
				count++;
			a = a->next;
			n--;
		}
		if (count == len - 1 && !b)
			return (1);
		if (count == len - 1)
			return (2);
	}
	return (0);
}

int	ft_check_sortb(t_list *a, int n)
{
	int	count;
	int	len;

	count = 0;
	len = n;
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->content >= a->next->content && a->next)
			count++;
		a = a->next;
	}
	if (count == len - 1)
		return (2);
	return (0);
}

int	ft_check_sortn(t_list *a, int len)
{
	int	count;
	int	n;

	count = 0;
	n = len;
	if (ft_lstlen(a) > 2)
	{
		while (a->next && n > 0)
		{
			if (a->content <= a->next->content && a->next)
				count++;
			a = a->next;
			n--;
		}
		if (count == len - 1)
			return (1);
	}	
	return (0);
}

int	ft_check_sort(t_list *a, t_list *b)
{
	int	count;
	int	len;

	count = 0;
	len = ft_lstlen(a);
	if (len == 1)
		return (2);
	if (len > 1)
	{
		while (a->next)
		{
			if (a->content <= a->next->content && a->next)
				count++;
			a = a->next;
		}
	}
	if (count == len - 1 && !b)
		return (1);
	if (count == len - 1)
		return (2);
	return (0);
}

int	ft_count_compare(t_list *a, t_list *a1, int n)
{
	t_list	*tmp;
	int		count;

	tmp = a;
	count = 0;
	while (tmp && n)
	{
		if (a1->content > tmp->content)
			count++;
		tmp = tmp->next;
		n--;
	}
	return (count);
}
