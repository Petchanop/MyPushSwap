/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:21:00 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/09 19:37:41 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char const *num);

t_list	*ft_intlst_new(int num);

void	ft_push_pab(t_list **a, t_list **b);

void	ft_print_lst(t_list *lst);

int	main(int argc, char **argv)
{
	int	i;
	int	lst;
	t_list	*a;
	t_list	*a1;
	t_list	*b;

	i = 1;
	lst = 0;
	a = NULL;
	a1 = NULL;
	b = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			lst = ft_atoi(argv[i]);
			a1 = ft_intlst_new(lst);
			ft_add_lst(&a, a1);
			i++;
		}
		ft_push_pab(&b, &a);
		a1 = a;
		a = a->next;
		free(a1);
		ft_show_ab(a, b);
		ft_push_pab(&b, &a);
		a1 = a;
		a = a->next;
		free(a1);
		ft_show_ab(a, b);
		ft_lstnumclear(&a);
		ft_lstnumclear(&b);
	}
	return (0);
}



