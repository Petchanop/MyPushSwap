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

int	ft_check_sort(t_slist *a, t_slist *b)
{
	int	count;
	int	len;

	count = 0;
	len = ft_slstlen(a);
	if (!b)
	{
		while (a)
		{
			if (a->num <= a->next->num && a->next)
				count++;
			a = a->next;
		}
		if (count == len)
			return (1);
	}
	return (0);
}

void	ft_show_ab(t_slist *a, t_slist *b)
{
	printf("---------------------------------------");
	printf("a	b\n");
	while (a || b)
	{
		if (a)
			printf("%d", a->num);
		printf("	");
		if (b)
			printf("%d", a->num);
		printf("\n");
	}
	printf("---------------------------------------");
	printf("\n");
}
