/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:05:12 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/24 14:37:26 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_lstat(t_list *lst, int n);

t_list	*ft_find_lst(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

int	ft_check_quater(t_list *a, int n);

int	ft_count_compare(t_list *a, t_list *a1, int n);

int	ft_check_sort(t_list *a, t_list *b);

int	ft_maxindex(t_list *a, t_list *max);

int	ft_minindex(t_list *a, t_list *min);

t_list	*ft_find_max(t_list *a, int n);

t_list	*ft_find_min(t_list *a, int n);

size_t	ft_lstlen(t_list *lst);

void	ft_rotate_lst(t_list *a);

void	ft_add_lstfront(t_list **lst, t_list *new);

void	ft_push_pab(t_list **a, t_list **b);

t_list	*ft_reverse_rotate(t_list **a);

int	reverse_or_rotate(t_list **a, t_list **b, t_list *max, t_list *min)
{
	t_list	*lhalf;
	t_list	*rhalf;
	t_list *maxb;
	t_list *mina;
	t_list *minb;
	t_list	*lasta;
	t_list	*lastb;
	t_list	*blasta;
	t_list	*blastb;
	int	sepa;
	int	sepb;

	sepa = 1;
	sepb = 1;
	if (ft_lstlen(*a) > 10 && ft_lstlen(*a) <= 20)
		sepa = 4;
	if (ft_lstlen(*b) > 10 && ft_lstlen(*b) <= 20)
		sepb = 4;
	if (ft_lstlen(*a) > 20 && ft_lstlen(*a) <= 100)
		sepa = 8;
	if (ft_lstlen(*b) > 20 && ft_lstlen(*b) <= 100)
		sepb = 8;
	
	maxb = ft_find_max(*b, ft_lstlen(*b) - 1);
	mina = ft_find_min(*a, ft_lstlen(*a) - 1); 
	minb = min;
	lasta = ft_lstlast(*a);
	lastb = ft_lstlast(*b);
	lhalf = ft_find_lstat(*a, ft_lstlen(*a) / 2);
	rhalf = ft_find_lstat(*b, ft_lstlen(*b) / 2);
	blasta = ft_find_lstat(*a, ft_lstlen(*a) - 2);
	if (ft_lstlen(*b) > 2)
		blastb = ft_find_lstat(*b, ft_lstlen(*b) - 2);
	if (ft_count_compare(*a, *a, ft_lstlen(*a)) > (int)ft_lstlen(*a) / sepa && ft_lstlen(*b) > 2 && ft_count_compare(*b, *b, ft_lstlen(*b)) < (int)ft_lstlen(*b) / sepb && lasta->content != max->content)
	{
		ft_rotate_all(*a, *b);
		printf("rr\n");
		return (1);
	}
	if ((ft_lstlen(*a) > 2 && ft_check_quater(*a, ft_lstlen(*a) - 1) >  (int)(3 * (ft_lstlen(*a) / 4))) && (ft_lstlen(*b) > 2 && (lastb->content > (*b)->content || ft_check_quater(*b, ft_lstlen(*b) - 1) >  (int)(3 * (ft_lstlen(*b) / 4))))) 
	{
		ft_reverse_all(a, b);
		printf("rrr\n");
		return (1);
	}
	if (ft_lstlen(*b) > 2 && ((ft_minindex(*b, minb) <= (int)ft_lstlen(*b) / 4 && (*b)->content < lastb->content) || (ft_count_compare(*b, *b, (ft_lstlen(*b))) < (int)ft_lstlen(*b) / 4)))
	{
		ft_rotate_lst(*b);
	 	printf("rb\n");
		if (ft_lstlen(*b) > 2 && (ft_check_quater(*b, ft_lstlen(*b) - 1) >  (int)(3 * (ft_lstlen(*b) / 4)) || (blastb->content < (lastb)->content && lastb->content > (*b)->content)))
		{
			ft_swap_bothab(*a, *b);	
			printf("ss\n");
		}
	 	return (1);
	}
	if (((ft_maxindex(*a, max) <= (int)ft_lstlen(*a) / sepa && (*a)->content > lasta->content) || (ft_count_compare(*a, *a, (ft_lstlen(*a))) > (int)ft_lstlen(*a) / sepa)))
	{
		ft_rotate_lst(*a);
 		printf("ra\n");
		if ((ft_lstlen(*a) > 2 && (ft_check_quater(*a, ft_lstlen(*a) - 1) > (int)(3 * (ft_lstlen(*a) / 4)) || (blasta->content > lasta->content && lasta->content < (*a)->content))))
		{
			ft_swap_bothab(*a, *b);
			printf("ss\n");
		}
 		return (1);
	}
	if ((ft_lstlen(*a) > 2 && (ft_check_quater(*a, ft_lstlen(*a) - 1) > (int)(3 * (ft_lstlen(*a) / 4)) || (blasta->content > lasta->content && lasta->content < (*a)->content))))
	{
		ft_reverse_rotate(a);
 		printf("rra\n");
		if ((ft_maxindex(*a, max) <= (int)ft_lstlen(*a) / sepa && (*a)->content > lasta->content) || (ft_count_compare(*a, *a, (ft_lstlen(*a))) > (int)ft_lstlen(*a) / sepa))
		{
			ft_swap_bothab(*a, *b);
			printf("ss\n");
			ft_push_pab(b, a);
			printf("pb\n");
		}
		return (1);
	}	
	if (ft_lstlen(*b) > 2 && (ft_check_quater(*b, ft_lstlen(*b) - 1) >  (int)(3 * (ft_lstlen(*b) / 4)) || (blastb->content < lastb->content && lastb->content > (*b)->content)))// || lastb->content > (*b)->content))  
	{
		ft_reverse_rotate(b);
	 	printf("rrb\n");
		if (ft_lstlen(*b) > 2 && ((ft_minindex(*b, minb) <= (int)ft_lstlen(*b) / 4 && (*b)->content < lastb->content) || (ft_count_compare(*b, *b, (ft_lstlen(*b))) < (int)ft_lstlen(*b) / 4)))
		{
			ft_swap_bothab(*a, *b);
			printf("ss\n");
			ft_push_pab(a, b);
			printf("pa\n");
		}
	 	return (1);
	}
	return (0);
}

void	push_swap(t_list **a, t_list **b, t_list *min)
{
	// t_list	*lhalf;
	// t_list	*rhalf;
	t_list	*lasta;
	t_list	*lastb;
	t_list	*blasta;
	t_list	*max;
	t_list *maxb;
	t_list *minb;
	// int	ua;
	// int	la;
	// int	uaa;
	// int	laa;
	// int	ub;
	// int	lb;
	// int	uab;
	// int	lab;
	int	sepa;
	
	max = ft_find_max(*a, ft_lstlen(*a) - 1); 
	maxb = ft_find_max(*b, ft_lstlen(*b) - 1);
	minb = ft_find_min(*b, ft_lstlen(*b) - 1);
	// lhalf = ft_find_lst(*a);
	// rhalf = ft_find_lst(*b);
	lasta = ft_lstlast(*a);
	lastb = ft_lstlast(*b);
	blasta = ft_find_lstat(*a, ft_lstlen(*a) - 2);
	// ua = ft_count_compare(*a, lasta, (ft_lstlen(*a) / 2));
	// la = ft_count_compare(lhalf, *a, (ft_lstlen(*a) / 2));
	// ub = ft_count_compare(*b, lastb, (ft_lstlen(*b) / 2));
	// lb = ft_count_compare(rhalf, *b, (ft_lstlen(*b) / 2));
	// uaa = ft_count_compare(*a, lasta, (ft_lstlen(*a) - 1));
	// laa = ft_count_compare(*a, *a, (ft_lstlen(*a) - 1));
	// uab = ft_count_compare(*b, lastb, (ft_lstlen(*b) - 1));
	// lab = ft_count_compare(*b, *b, (ft_lstlen(*b) - 1));

	sepa = 1;
	if (ft_lstlen(*a) > 20 && ft_lstlen(*a) <= 100)
		sepa = 8;
	if (reverse_or_rotate(a, b, max, min))
		return ;
	if (*a)
	{
		if (*b && ft_lstlen(*b) > 1)
		{
			if ((*a)->content > (*a)->next->content && (*b)->content < (*b)->next->content)
			{
				ft_swap_bothab(*a, *b);
				printf("ss\n");
				return ;	
			}
			if ((*b)->content < (*b)->next->content)
			{
				ft_swap_ab(*b);
				printf("sb\n");
				return ;
			}
		}
		if (ft_lstlen(*a) > 1 && (*a)->content > (*a)->next->content)
		{
			ft_swap_ab(*a);
			printf("sa\n");
			return ;
		}
	}
	if ((ft_count_compare(*a, *a, ft_lstlen(*a)) < (int)ft_lstlen(*a) / 4 
			&& !ft_check_sort(*a, *b)) || (lasta->content != max->content && !ft_check_sort(*a, *b))) 
	{
		ft_push_pab(b, a);
		printf("pb\n");
		return ;
	}
	if (*b && (((*b)->content < (*a)->content && (ft_check_sort(*a, *b)) && ((*b)->next && (*b)->content > (*b)->next->content)) || (ft_check_sort(*a, *b) == 2 && ft_lstlen(*b) == 1)))
	{
		ft_push_pab(a, b);
		printf("pa\n");
		return ;
	}
	if (*b && (*b)->content < (*a)->content && ft_check_sort(*a, *b))
	{
		ft_push_pab(a, b);
		printf("pa\n");
		return ;
	}
	else  
	{
		ft_push_pab(b, a);
		printf("pb\n");
		return ;
	}
}


			

		
