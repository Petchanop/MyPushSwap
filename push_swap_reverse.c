/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:52:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/22 17:28:22 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **a)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*del;

	head = NULL;
	tmp = NULL;
	if (*a)
	{
		tmp = *a;
		while (tmp->next != NULL)
		{
			del = tmp;
			tmp = tmp->next;
		}
		tmp->next = *a;
		*a = tmp;
		del->next = NULL;
	}
}

void	ft_reverse_all(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
