/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:52:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/05 19:01:10 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*del;

	tmp = *a;
	if (*a && ft_lstlen(*a) > 1)
	{
		while (tmp->next != NULL)
		{
			del = tmp;
			tmp = tmp->next;
		}
		tmp->next = *a;
		*a = tmp;
		del->next = NULL;
		if (!*b)
			*b = NULL;
	}
}

void	ft_reverse_all(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		ft_reverse_rotate(a, b);
		ft_reverse_rotate(b, a);
	}
}
