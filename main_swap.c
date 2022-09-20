/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:07:53 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/20 17:29:40 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_queue	len;
	static	t_list	*a;
	static	t_list	*b;

	a = NULL;
	b = NULL;
	len.start = 1;
	len.end = 0;
	if (argc > 1)
	{
		format_input(argv, argc, &a);
		add_index(&a);
		ft_show_ab(a, b);
		len.range = ft_lstlen(a);
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

