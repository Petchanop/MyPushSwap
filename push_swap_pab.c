/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:59:12 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/04 21:56:50 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_slist	*ft_intlst_new(int num);

void	ft_add_slstfront(t_slist **lst, t_slist *new);

void	ft_delslst(t_slist **lst);

void	ft_push_pab(t_slist **a, t_slist *b)
{
	t_slist	*tmp;

	tmp = NULL;
	if (b)
	{
		if (!a)
			*a = ft_intlst_new((b)->num);
		else
		{
			tmp = ft_intlst_new((b)->num);
			ft_add_slstfront(a, tmp);
		}
		ft_delslst(&b);
	}
}
