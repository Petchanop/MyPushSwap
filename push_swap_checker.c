/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:44:33 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/30 01:53:44 by npiya-is         ###   ########.fr       */
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
		read_operations(&a, &b);
		if (ft_check_sort(a, b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_lstnumclear(&a);
		ft_lstnumclear(&b);
	}
	return (0);
}
/*ft_show_ab(a, b);*/
