/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:07:53 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/27 21:22:36 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
