/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:11:47 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/05 17:18:50 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_slist	*ft_slstlast(t_slist *lst);

size_t	ft_slstlen(t_slist *lst);

void	ft_rotate_lst(t_slist *a)
{
	t_slist	*tmp;
	size_t	len;
	int		temp;

	tmp = NULL;
	if (a)
	{
		len = ft_slstlen(a);
		tmp = a;
		while (len > 1)
		{
			temp = tmp->num;
			tmp->num = tmp->next->num;
			tmp->next->num = temp;
			tmp = tmp->next;
			len--;
		}
	}
}

void	ft_rotate_all(t_slist *a, t_slist *b)
{
	ft_rotate_lst(a);
	ft_rotate_lst(b);
}