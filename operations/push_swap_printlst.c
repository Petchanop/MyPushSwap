/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_printlst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:31:11 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/28 19:35:07 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_list *lst)
{
	if (lst)
	{
		ft_printf("%ld", lst->content);
		ft_printf("		");
		ft_printf("%d", lst->index);
		lst = lst->next;
	}
	else
		return ;
}

void	ft_show_ab(t_list *a, t_list *b)
{
	ft_printf("---------------------------------------");
	ft_printf("\na			b\n");
	while (a || b)
	{
		if (!a)
			ft_printf("	");
		if (a)
		{
			ft_printf("%ld	", a->content);
			ft_printf("%d", a->index);
			a = a->next;
		}
		ft_printf("		");
		if (b)
		{
			ft_printf("%ld	", b->content);
			ft_printf("%d", b->index);
			b = b->next;
		}
		printf("\n");
	}
	ft_printf("---------------------------------------");
	ft_printf("\n");
}
