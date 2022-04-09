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

t_slist	*ft_intlst_new(int num);

void	ft_push_pab(t_slist **a, t_slist *b);

void	ft_print_slst(t_slist *lst);

int	main(int argc, char **argv)
{
	int	i;
	int	lst;
	t_slist	*a;
	t_slist	*a1;
	t_slist	*b;

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
			ft_add_slst(&a, a1);
			i++;
		}
		//ft_print_slst(a);
		ft_push_pab(&b, a);
		a1 = a;
		a = a->next;
		free(a1);
		//ft_push_pab(&a, a);
		ft_push_pab(&b, a);
		a1 = a;
		a = a->next;
		free(a1);
		//ft_push_pab(&b, a);
		ft_print_slst(a);
		printf("\n");
		ft_print_slst(b);
		ft_slstclear(&a);
		ft_slstclear(&b);
	}
	return (0);
}



