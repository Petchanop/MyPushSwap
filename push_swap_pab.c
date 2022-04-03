/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:59:12 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/03 23:57:05 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_slist	*ft_intlst_new(int num);

void	ft_add_slstfront(t_slist **lst, t_slist *new);

void	ft_delslst(t_slist **lst);

t_slist	*ft_push_pab(t_slist **a, t_slist *b)
{
	t_slist	*tmp;

	tmp = NULL;
	if (a)
	{
		if (!b)
			b = ft_intlst_new((*a)->num);
		else
		{
			tmp = ft_intlst_new((*a)->num);
			ft_add_slstfront(&b, tmp);
		}
		tmp = *a;
		ft_delslst(a);
		free(tmp);
	}
	return (b);
}
