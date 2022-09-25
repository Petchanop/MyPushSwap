/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:07:53 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/25 01:33:01 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue	initialize_tqueue(t_queue que, t_list *a)
{
	size_t	len;
	size_t	n;

	len = ft_lstlen(a);
	if (len > 20 && len <= 100)
		n = len / 5;
	if (len > 100)
		n = len / 8;
	if (len <= 20)
		n = len;
	que.start = 1;
	que.end = n;
	que.section = n;
	que.median = (que.start + que.end) / 2;
	que.range = len;
	return (que);
}

int	main(int argc, char **argv)
{
	t_queue			len;
	static t_list	*a;
	static t_list	*b;

	a = NULL;
	b = NULL;
	len.start = 1;
	len.end = 0;
	if (argc > 1)
	{
		check_empty(argv);
		format_input(argv, argc, &a);
		add_index(&a);
		len = initialize_tqueue(len, a);
		//ft_show_ab(a, b);
		push_swap(&a, &b, len);
		if (ft_check_sort(a, b))
		{
			ft_lstnumclear(&a);
			ft_lstnumclear(&b);
			return (0);
		}
	}
	return (0);
}
