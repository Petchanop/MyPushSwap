/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:13:08 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/21 20:14:17 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_count_compare(t_list *a, t_list *a1);

int	ft_check_sort(t_list *a, t_list *b);

size_t	ft_lstlen(t_list *lst);

t_list	*ft_find_lst(t_list *lst);

void push_swap(t_list **a, t_list **b);

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
        printf("%d\n", ft_check_sort(a, b));
    }
}

