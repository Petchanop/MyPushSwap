/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:57:58 by npiya-is          #+#    #+#             */
/*   Updated: 2022/05/30 23:48:28 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_lstat(t_list *lst, int n);

t_list	*ft_find_lst(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

int	ft_find_lstindex(t_list *lst, int n);

int	ft_check_sort_n(t_list *a, t_list *b, int n);

int	ft_check_sortb(t_list *a, int n);

int	ft_check_quater(t_list *a, int n);

int	ft_count_compare(t_list *a, t_list *a1, int n);

int	ft_check_sort(t_list *a, t_list *b);

int	ft_maxindex(t_list *a, t_list *max);

int	ft_minindex(t_list *a, t_list *min);

int	ft_find_maxn(t_list *a, int n);

int	ft_find_minn(t_list *a, int n);

int	ft_check_sortn(t_list *a, int len);

t_list	*ft_find_max(t_list *a, int n);

t_list	*ft_find_min(t_list *a, int n);

size_t	ft_lstlen(t_list *lst);

void	ft_rotate_lst(t_list *a);

void	ft_add_lstfront(t_list **lst, t_list *new);

void	ft_push_pab(t_list **a, t_list **b);

void	r_orrr_max(t_list **a, t_list **b, int len);

void	sort_stack_b(t_list **a, t_list **b, t_queue len)
{
	int	index;
	t_list	*lastb;
	t_list	*lasta;

	index = (int)ft_lstlen(*b);
	lasta = ft_lstlast(*a);
	lastb = ft_lstlast(*b);
	
	while (!ft_check_sortb(*b, index) && index > 1)
	{
		if ((*b)->index < (*b)->next->index)
    	{
			if ((*a)->index > (*a)->next->index && (*a)->index < len.start && (*a)->index > len.end) 
        	{
				ft_swap_bothab(*a, *b);	
				printf("ss\n");
			}
			else
			{
				ft_swap_ab(*b);
  	 	    	printf("sb\n");
			}
		}
		else if (lastb->index > (*b)->index && lastb->index > index / 2)
		{
			if (lasta->index >= (len.start + 10) && lasta->index <= (len.end + 10))
			{
				ft_reverse_all(a, b);
				printf("rrr\n");
			}
			else
			{
				ft_reverse_rotate(b);
 				printf("rrb\n");
			}
		}
		else if (lastb->index > (*b)->index && lastb->index <= index / 2)
		{
			if ((*a)->index < len.start + 10 && (*a)->index > len.end + 10)
			{
				ft_rotate_all(*a, *b);
				printf("rr\n");
			}
			else
			{
				ft_rotate_lst(*b);
 				printf("rb\n");
			}
		}
		else if (((*b)->index == len.end || (*b)->index >= index) && !ft_check_sortb(*b, index) && ft_lstlen(*b) > 2)
		{
			ft_push_pab(a, b);
			printf("pa\n");
			index--;
		}
	}
	return ;
}

void	sort_stack(t_list **a, t_list **b, t_queue len)
{
	int	i;

	i = 0;
	while (!ft_check_sortb(*b, len.end)) 
	{
		if ((*a)->index >= len.start && (*a)->index <= len.end)
		{
			ft_push_pab(b, a);
			printf("pb\n");
		}
		if (ft_lstlen(*b) > 1)
			sort_stack_b(a, b, len);
		if ((*a)->index < len.start || (*a)->index > len.end)  
		{
			ft_rotate_lst(*a);
 			printf("ra\n");	
		}
	}	
	if (ft_check_sortn(*a, len.end - len.start) && ft_check_sortb(*b, len.end))
	{
		ft_push_pab(a, b);
		printf("pa\n");	
	}
	return ;
}

void	sort_stack_a(t_list **a, t_list **b, t_queue len)
{
	t_list	*lasta;
	t_list	*mina;
	int	i;
	int	index;

	i = 0;
	index = (int)ft_lstlen(*a);
	mina = ft_find_min(*a, ft_lstlen(*a));
	while (ft_check_sort(*a, *b) != 1 && ft_lstlen(*b) != 1)
	{
		lasta = ft_lstlast(*a);
		if ((*a)->index > (*a)->next->index || (*b)->index < (*b)->next->index)
		{
			if ((*b)->index < (*b)->next->index && (*a)->index > (*a)->next->index)
			{
				ft_swap_bothab(*a, *b);	
				printf("ss\n");	
			}
			else if ((*a)->index > (*a)->next->index) 
			{
				ft_swap_ab(*a);
				printf("sa\n");
			}
			else if ((*b)->index < (*b)->next->index)
			{
				ft_swap_ab(*b);
  	 	    	printf("sb\n");	
			}
		}
		else if ((*a)->index < (len.end + len.start) / 2 && !ft_check_sort_n(*a, *b, ft_lstlen(*a)))
		{
			ft_push_pab(b, a);
			printf("pb\n");
			index--;
		}
		else if (lasta->index != len.end)
		{
			if (ft_find_maxn(*a, len.end) > (len.start + len.end) / 2)
			{
				while (lasta->index != len.end)
				{
					ft_reverse_rotate(a);
 					printf("rra\n");
				} 
			}
			else
			{
				while (lasta->index != len.end)
				{
					ft_rotate_lst(*a);
 					printf("ra\n");
				}	
			}
			continue;
		}
		else if (ft_check_sort_n(*a, *b, ft_lstlen(*a)))
		{
			ft_push_pab(a, b);
			printf("pa\n");
			index++;
		}
		else if ((lasta->index == len.end || mina->index == (*a)->index) && !ft_check_sortn(*a, ft_lstlen(*a)) && ft_lstlen(*a) > 1) 
		{
			ft_push_pab(b, a);
			printf("pb\n");
			index--;
		}
//	ft_show_ab(*a, *b);
	}
	ft_push_pab(a, b);
	printf("pa\n");
	return ;
}

void	push_swap(t_list **a, t_list **b, t_queue len)
{
	int	n;
	int	i;
	
	n = 10;
	i = 0;

	if (len.range >= 50 && len.range < 100)
		n = 5;
	else if (len.range >= 100 && len.range <= 500)
		n = 10;
	len.end = n;
	while (ft_check_sort(*a, *b) != 1) 
	{
		if ((int)ft_lstlen(*a) <= n)
			sort_stack_a(a, b, len);
		else
			sort_stack(a, b, len);
		len.start += n;
		len.end += n;
		i++;
	}
	return ;
}