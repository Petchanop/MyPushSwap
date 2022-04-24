/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:04:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/21 18:22:57 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_count_compare(t_list *a, t_list *a1, int n);

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
       // ft_show_ab(a, b);
        printf("test1: %d\n",ft_count_compare(a, a, ft_lstlen(a)));
        printf("test2: %d\n",ft_count_compare(a, a->next, ft_lstlen(a)));
        printf("test3: %d\n",ft_count_compare(a, a->next->next, ft_lstlen(a) / 2));
        ft_push_pab(&b, &a);
        ft_push_pab(&b, &a);
		ft_show_ab(a, b);
        printf("test4: %d\n",ft_count_compare(a, b->next, ft_lstlen(a)));
        printf("test5: %d\n",ft_count_compare(a, b, ft_lstlen(a)));
    }
}

