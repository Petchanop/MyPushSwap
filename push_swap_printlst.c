/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_printlst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:31:11 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/25 16:53:20 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%ld\n", lst->content);
		lst = lst->next;
	}
}

void	ft_show_ab(t_list *a, t_list *b)
{
	printf("---------------------------------------");
	printf("\na			b\n");
	while (a || b)
	{
		if (!a)
			printf("	");	
		if (a)
		{
			printf("%ld	", a->content);
			printf("%d", a->index);
			a = a->next;
		}
		printf("		");
		if (b)
		{
			printf("%ld	", b->content);
			printf("%d", b->index);
			b = b->next;
		}
		printf("\n");
	}
	printf("---------------------------------------");
	printf("\n");
}
