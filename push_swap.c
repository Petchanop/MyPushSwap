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

t_list	*ft_find_lst(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

int	ft_count_compare(t_list *a, t_list *a1, int n);

int	ft_check_sort(t_list *a, t_list *b);

size_t	ft_lstlen(t_list *lst);

void	ft_rotate_lst(t_list *a);

void	ft_add_lstfront(t_list **lst, t_list *new);

void	ft_push_pab(t_list **a, t_list **b);

t_list	*ft_reverse_rotate(t_list **a);

void	push_swap(t_list **a, t_list **b)
{
	t_list	*lhalf;
	t_list	*rhalf;
//	t_list	*luphalf;
//	t_list	*ruphalf;
	t_list	*lasta;
	t_list	*lastb;
	
	lhalf = ft_find_lst(*a);
	rhalf = ft_find_lst(*b);
	lasta = ft_lstlast(*a);
	if (*b)
		lastb = ft_lstlast(*b);
	printf("upper : %d\n", ft_count_compare(*a, lasta, (int)(ft_lstlen(*a) / 2)));
	printf("lower : %d\n", ft_count_compare(lhalf, *a, (int)(ft_lstlen(*a) / 2)));
	if (ft_count_compare(lhalf, *a, (ft_lstlen(*a) / 2)) > ft_count_compare(*a, lasta, (int)(ft_lstlen(*a) / 2)))
	{
		if (ft_count_compare(rhalf, *b, (int)(ft_lstlen(*b) / 2)) < (int)(ft_lstlen(*b) / 2) - 1)
		{
			ft_reverse_all(a, b);
			printf("reall\n");
			return ;
		}
		else
		{
			ft_rotate_lst(*a);
			printf("ra\n");
			return ;
		}
	}
	if (ft_count_compare(*a, lasta, (ft_lstlen(*a) / 2)) < ft_count_compare(lhalf, *a, (ft_lstlen(*a) / 2)))
	{
		ft_reverse_rotate(a);
		printf("rra\n");
		return ;
	}
//	if (ft_count_compare(lhalf, *a, (ft_lstlen(*a) / 2)) > ft_count_compare(*a, lasta, (ft_lstlen(*a) / 2)))
//	{


//	}
	if (*a && ft_lstlen(*b) > 1)
	{
		if ((*a)->content > (*a)->next->content && (*b)->content < (*b)->next->content)
		{
			ft_swap_ab(*a);	
			ft_swap_ab(*b);
			printf("sab\n");
			return ;	
		}
	}
	if ((*a)->content > (*a)->next->content)
	{
		ft_swap_ab(*a);
		printf("sa\n");
		return ;
	}
	if ((*b)->content > (*b)->next->content)
	{
		ft_swap_ab(*b);
		printf("sb\n");
		return ;
	}
/*	if (*b && !ft_count_compare(*a, *b, (ft_lstlen(*a))) && ft_check_sort(*a, *b))
	{
		ft_push_pab(a, b);
		printf("pa\n");
		return ;
	}
	else //if (!ft_count_compare(*a, *b, (ft_lstlen(*a))))
	{
		ft_push_pab(b, a);
		printf("pb\n");
		return ;	
	}*/
	
		//ft_swap_ab(*a);	
		//ft_swap_ab(*b);	
		//ft_push_pab(b, a);
		//ft_push_pab(a, b);
		//ft_reverse_rotate(a);
		//ft_reverse_rotate(b);
		//ft_rotate_lst(*a);
		//ft_rotate_lst(*b);
		//ft_swap_bothab(*a, *b);
		//ft_rotate_all(*a, *b)
		//ft_reverse_all(a, b);
		
}


			

		
