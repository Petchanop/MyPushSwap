/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:05:12 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/09 19:18:07 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char *str, t_list *a, t_list *b)
{
		ft_swap_ab(a);
		ft_swap_ab(b);
		ft_swap_bothab(a, b);
		ft_push_pab(&a, b);
		ft_push_pab(&b, a);
		ft_rotate_lst(a);
		ft_rotate_lst(b);
		ft_rotate_all(a, b);
		ft_reverse_rotate(&a);
		ft_reverse_rotate(&b);
		ft_reverse_all(&a, &b);
}

int	main(int argc, char **argv)
{
	int	i;
	static	t_list	*a;
	static	t_list	*a1;
	static	t_list	*b;

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
				push_swap(argv[i], a, b);
				i++;
			}
			printf(":\n");
			ft_show_ab(a, b);
		}
	}
	/*if (ft_check_sort(a, b))
	{
		ft_slstclear(&a);
		ft_slstclear(&b);
	}*/
	return (0);
}

			

		
