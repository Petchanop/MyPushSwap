/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:52:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/09 19:18:31 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_slist	*ft_intlst_new(int num);

t_slist	*ft_slstlast(t_slist *lst);

size_t	ft_slstlen(t_slist *lst);

void	ft_delslst(t_slist **lst);

void	ft_add_slstfront(t_slist **lst, t_slist *new);

void	ft_reverse_rotate(t_slist **a)
{
	t_slist	*re;
	t_slist	*del;
	t_slist	*tmp;

	re = NULL;
	tmp = NULL;
	if (a)
	{
		del = ft_slstlast(*a);
		re = ft_intlst_new(del->num);
		ft_add_slstfront(a, re);
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		free(tmp->next);
	}
}

void	ft_reverse_all(t_slist **a, t_slist **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
