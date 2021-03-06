/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:59:12 by npiya-is          #+#    #+#             */
/*   Updated: 2022/06/02 15:39:47 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_lstlen(t_list *lst);

t_list	*ft_intlst_new(int content, int index);

void	ft_add_lstfront(t_list **lst, t_list *new);

void	ft_dellst(t_list **lst);

void	ft_push_pab(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!*b)
		return ;
	if (!ft_lstlen(*a))
		*a = ft_intlst_new((*b)->content, (*b)->index);
	else
	{
		tmp = ft_intlst_new((*b)->content, (*b)->index);
		ft_add_lstfront(a, tmp);
	}
	tmp = *b;
	*b = (*b)->next;
	free(tmp);
	tmp = NULL;
}
