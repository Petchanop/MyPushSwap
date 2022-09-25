/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:59:12 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/22 16:53:16 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_lstlen(t_list *lst);

void	ft_push_pab(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!*b)
		return ;
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
}
