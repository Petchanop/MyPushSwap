/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:05:12 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/05 19:40:39 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char *str, t_slist *a, t_slist *b)
{
	if (str == "sa")
		ft_swap_ab(a);
	if (str == "sb")
		ft_swap_ab(b);
	if (str == "ss")
		ft_swap_bothab(a, b);
	if (str == "pa")
		ft_push_pab(&a, b);
	if (str == "pb")
		ft_push_pab(&b, a);
	if (str == "ra")
		ft_rotate_lst(a);
	if (str == "rb")
		ft_rotate_lst(b);
	if (str == "rr")
		ft_rotate_all(a, b);
	if (str == "rra")
		ft_reverse_rotate(&a);
	if (str == "rrb")
		ft_reverse_rotate(&b);
	if (str == "rrr")
		ft_reverse_all(&a, &b);
}

int	main(int argc, char **argv)
{
	int	i;
	static	t_slist	*a;
	static	t_slist	*a1;
	static	t_slist	*b;

	a = NULL;
	a1 = NULL;
	b = NULL;
	i = 1;
	if (argc > 1)
	{
		if (ft_atoi(argv[i]))
		{
			printf("init a and b :\n");
			while (i < argc)
			{
				a1 = ft_intlst_new(ft_atoi(argv[i]));
				ft_add_slst(&a, a1);
				i++;
			}
			ft_show_ab(a, b);
		}
		else
		{
			printf("exec : ");
			while (i < argc)
			{
				printf("%s", argv[i]);
				if (i < argc - 1)
					printf(" ", argv[i]);
				push_swap(argv[i]);
				i++;
			}
			printf(":\n");
			ft_show_ab(a, b);
		}
	}
	if (ft_check_sort(a, b))
	{
		ft_slstclear(&a);
		ft_slstclear(&b);
	}
	return (0);
}

			

		
