/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:28:22 by npiya-is          #+#    #+#             */
/*   Updated: 2022/06/14 00:50:13 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_lstat(t_list *lst, int n);

t_list	*ft_find_lst(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

int	find_next(t_list *a, int n);

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

t_list	*ft_find_lstat(t_list *lst, int n);

size_t	ft_lstlen(t_list *lst);

void	ft_rotate_lst(t_list *a);

void	ft_add_lstfront(t_list **lst, t_list *new);

void	ft_push_pab(t_list **a, t_list **b);

void	sort_stack_a(t_list **a, t_list **b);//, t_queue len);//, t_queue len);

int	find_next_index(t_list *a, t_queue n)
{
	int index;

	index = 1;
	while (a)
	{
		if ((a)->index >= n.start && (a)->index <= n.end)
			return (index);
		a = (a)->next;
		index++;
	}
	return (index);
}

int	find_next(t_list *a, int n)
{
	int index;

	index = 1;
	while (a)
	{
		if ((a)->index == n)
			return (index);
		a = (a)->next;
		index++;
	}
	return (index);
}

int	find_last_index(t_list *a, t_queue n)
{
	int index;
	int	tmp;

	index = 1;
	tmp = 1;
	while (a)
	{
		if ((a)->index >= n.start && (a)->index <= n.end)
			tmp = index;
		a = (a)->next;
		index++;
	}
	return (tmp);
}

void	sort_stack(t_list **a, t_list **b, t_queue len)
{
	int	i;
	int	lstindex;
	int	lastindex;
	t_list	*lsta;
	t_list	*maxa;
	t_list	*lastb;

	i = 0;
	maxa = ft_find_max(*a, ft_lstlen(*a));
	while (!ft_check_sortb(*b, len.end) && (int)ft_lstlen(*b) != len.end && ft_lstlen(*a) > 3) 
	{
		lstindex = find_next_index(*a, len);	
		if (*b)
			lastb = ft_lstlast(*b);
		
		if ((*a)->index >= len.start && (*a)->index <= len.end && (*a)->index != len.range)
		{
			ft_push_pab(b, a);
			printf("pb\n");
		}
		lastindex = find_last_index(*a, len);
		while (lstindex != 1 && (int)ft_lstlen(*b) != len.end )//&& )
		{
			lsta = ft_find_lstat(*a, lstindex - 1);
			if (ft_lstlen(*b) > 2 && (*b)->index < len.median)
			{
				ft_rotate_all(*a, *b);
				printf("rr\n");
			}
			else
			{
				ft_rotate_lst(*a);
				printf("ra\n");
			}
			lstindex--;
		}
		if (!((*a)->index >= len.start && (*a)->index <= len.end) && ft_lstlen(*b) > 2 && (*b)->index < len.median)
		{
			ft_rotate_all(*a, *b);
			printf("rr\n");
		}
		if (ft_lstlen(*b) > 2 && (*b)->index < len.median)
		{
			ft_rotate_lst(*b);
			printf("rb\n");	
		}
		//ft_show_ab(*a, *b);
		i++;
	}
	//ft_show_ab(*a, *b);
	return ;
}

void	sort_stack_a(t_list **a, t_list **b)
{
	t_list	*maxa;
	t_list	*maxb;
	t_list	*lasta;
	int	i;
	int	j;
	int lstindex;	
	int	rindex;
	int	pbindex;

	i = 0;
	lstindex = 0;
	rindex = 0;
	pbindex = 0;
	j = 0;
	lasta = ft_lstlast(*a);
	maxa = ft_find_max(*a, ft_lstlen(*a));
	while (ft_check_sort(*a, *b) != 1)// && i < 3053)
	{
		//printf("%d %d\n", lstindex, maxb->index);
		//printf("check : %d %zu\n", ft_check_sort(*a, *b), ft_lstlen(*b));
		maxb = ft_find_max(*b, ft_lstlen(*b));
		lstindex = ft_find_maxn(*b, maxb->index);
		
		if (lasta->index != maxa->index)
		{
			while (lasta->index != maxa->index)// && j < 1)
			{
				ft_rotate_lst(*a);
 				printf("ra\n");
				maxa = ft_find_max(*a, ft_lstlen(*a));
				lasta = ft_lstlast(*a);
				j++;
			}
		} 
		if ((*a)->index < maxb->index && ft_check_sort_n(*a, *b, ft_lstlen(*a)) != 1 )//&& lstindex != 1)
		{
			while ((*a)->index < maxb->index)// && ft_lstlen(*a) > 1)
			{
				ft_push_pab(b, a);
				printf("pb\n");
				//ft_show_ab(*a, *b);
				pbindex++;
			}
			i += pbindex;
		}
		if (ft_lstlen(*a) < 4 && ft_lstlen(*a) >= 2 && (*a)->index > (*a)->next->index)
		{
			ft_swap_ab(*a);
			printf("sa\n");
		}
		if (ft_lstlen(*b) == 2 && (*b)->index < (*b)->next->index)
		{
			ft_swap_ab(*b);
  	    	printf("sb\n");	
		}
		//ft_show_ab(*a, *b);
	
		if ((*b)->index != maxb->index && ft_lstlen(*b) >= 3)
		{
			while ((lstindex != 1 || lstindex < (int)ft_lstlen(*b)) && (*b)->index != maxb->index)
			{
				maxb = ft_find_max(*b, ft_lstlen(*b));
				lstindex = ft_find_maxn(*b, maxb->index);
				//printf("%d %d %d %zu\n", lstindex, maxb->index, (*b)->index, ft_lstlen(*b));
				if (lstindex < (int)(ft_lstlen(*b) / 2))
				{
					ft_rotate_lst(*b);
					printf("rb\n");
					if (ft_check_sort_n(*a, *b, ft_lstlen(*a)) && (*b) && (*a)->index == (*b)->index + 1)
					{
						ft_push_pab(a, b);
						printf("pa\n");
					}
				}
				else
				{
					ft_reverse_rotate(b);
					printf("rrb\n");
				}
				rindex++;
			}
			//ft_show_ab(*a, *b);
			i += rindex;
			rindex = 0;
		}
		if (ft_check_sort_n(*a, *b, ft_lstlen(*a)) && (*b) && (*a)->index == (*b)->index + 1)
		{
			ft_push_pab(a, b);
			printf("pa\n");
			if (ft_check_sort(*a, *b) == 1)
			{
			//	ft_show_ab(*a, *b);
				exit(0);
			}
		}
		if (ft_lstlen(*b) > 1 && ft_check_sort_n(*a, *b, ft_lstlen(*a)) != 1 && (*a)->index < (*b)->index)
		{
			ft_push_pab(b, a);
			printf("pb\n");
			//ft_show_ab(*a, *b);
		}
	//	ft_show_ab(*a, *b);
		i++;
	}
//	ft_show_ab(*a, *b);
	return ;
}

void	push_swap(t_list **a, t_list **b, t_queue len)
{
	int	n;
	int	i;
	
	if (ft_lstlen(*a) > 20 && ft_lstlen(*a) <= 100)
		n = 20;
	if (ft_lstlen(*a) > 100)
		n = 50;
	if (ft_lstlen(*a) <= 20)
		n = 5;
	i = 0;
	len.start = 1;
	len.end = n;
	len.median = n / 2;
	//ft_show_ab(*a, *b);
	while (ft_check_sort(*a, *b) != 1)// && i < 12) 
	{
		if ((int)ft_lstlen(*a) > n)
			sort_stack(a, b, len);
		else if ((int)ft_lstlen(*a) <= n && (int)ft_lstlen(*a) > 3) 
		{
			if (len.end == len.range)
				len.end--;
			sort_stack(a, b, len);
			i++;
			continue;
		}
		else
		{
		//	ft_show_ab(*a, *b);
			sort_stack_a(a, b);
			exit(0);
		}
	//	ft_show_ab(*a, *b);
		len.start = len.end + 1;
		len.end += n;
		len.median = (len.end + len.start) / 2;
		i++;
	}
//	ft_show_ab(*a, *b);
	return ;
}