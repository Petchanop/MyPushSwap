/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:31:11 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/05 18:44:21 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_list *a, t_list *b)
{
	int	count;
	int	len;

	count = 0;
	len = ft_lstlen(a);
	if (!b)
	{
		while (a->next)
		{
			if (a->content <= a->next->content && a->next)
				count++;
			a = a->next;
		}
		if (count == len - 1)
			return (1);
	}
	return (0);
}

void	ft_show_ab(t_list *a, t_list *b)
{
	printf("---------------------------------------");
	printf("\na	b\n");
	while (a || b)
	{
		if (a)
		{
			printf("%d", a->content);
			a = a->next;
		}
		printf("	");
		if (b)
		{
			printf("%d", b->content);
			b = b->next;
		}
		printf("\n");
	}
	printf("---------------------------------------");
	printf("\n");
}
