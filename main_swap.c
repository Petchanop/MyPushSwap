/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:07:53 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/13 18:07:54 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_compare(t_list *a, t_list *a1);

size_t	ft_lstlen(t_list *lst);

t_list	*ft_find_lst(t_list *lst);

void push_swap(t_list **a, t_list **b);

void	ft_lstnumclear(t_list **lst);

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
				ft_add_lst(&a, a1);
				i++;
			}
			ft_show_ab(a, b);
		}
		i = 0;
		while (i < 8)
		{
			push_swap(&a, &b);
			ft_show_ab(a, b);
			if (ft_check_sort(a, b))
			{
				ft_lstnumclear(&a);
				ft_lstnumclear(&b);
				return (0);
			}
			i++;
		}
	}
	return (0);
}

