/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:07:53 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/18 20:58:23 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_compare(t_list *a, t_list *a1, int n);

size_t	ft_lstlen(t_list *lst);

t_list	*ft_find_lst(t_list *lst);

t_list	*ft_find_max(t_list *a, int n);

t_list	*ft_find_min(t_list *a, int n);

void push_swap(t_list **a, t_list **b, t_queue min);

void	ft_lstnumclear(t_list **lst);

int	main(int argc, char **argv)
{
	int	i;
	t_queue	len;
	t_list	*min;
	static	t_list	*a;
	static	t_list	*b;
	t_list	*a1;

	a = NULL;
	a1 = NULL;
	b = NULL;
	i = 1;
	len.start = 1;
	len.end = 0;
	if (argc > 1)
	{
		if (ft_atoi(argv[i]) || !ft_atoi(argv[i]))
		{
			while (i < argc)
			{
				a1 = ft_intlst_new(ft_atoi(argv[i]), i);
				ft_add_lst(&a, a1);
				i++;
			}
			//ft_show_ab(a, b);
		}
		i = 0;
		a1 = a;
		while (i < (int)ft_lstlen(a))
		{
			a1->index = ft_count_compare(a, a1, ft_lstlen(a)) + 1;
			a1 = a1->next;
			i++;
		}
		min = ft_find_min(a, ft_lstlen(a) - 1);
		len.range = ft_lstlen(a);
		i = 0;
		push_swap(&a, &b, len);
		//ft_show_ab(a, b);
		if (ft_check_sort(a, b))// && !b)
		{
			//ft_lstnumclear(&a1);
			ft_lstnumclear(&a);
			ft_lstnumclear(&b);
			return (0);
		}
	}
	return (0);
}

