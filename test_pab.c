/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:40:00 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/22 16:58:50 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_list	*a;
	static t_list	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		format_input(argv, argc, &a);
		add_index(&a);
		ft_show_ab(a, b);
		ft_reverse_rotate(&a);
		// ft_push_pab(&b, &a);
		ft_show_ab(a, b);
		// ft_push_pab(&b, &a);
		//ft_push_pab(&b, &a);
		ft_reverse_rotate(&a);
		ft_show_ab(a, b);
	}
}