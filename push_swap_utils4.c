/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:29:26 by npiya-is          #+#    #+#             */
/*   Updated: 2022/06/10 18:00:05 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_lstlen(t_list *lst);

t_list	*ft_find_lstat(t_list *lst, int n);

t_list	*ft_find_min(t_list *a, int n);

int	ft_minindex(t_list *a, t_list *min);

int	ft_count_compare(t_list *a, t_list *a1, int n);

int	ft_check_quater(t_list *a, int n)
{
    t_list  *min;
    t_list  *half;
    int i;
    int count;

    min = NULL;
    half = NULL;
    count = 0;
    i = n / 4;
    if (a)
    {
        min = ft_find_min(a, ft_lstlen(a) - 1);
        half = ft_find_lstat(a, n / 2);
        while (i)
        {
            count += ft_count_compare(a, half, ft_lstlen(a) - 1);
            half = half->next;
            i--;
        }
        count /= n;
        return (count * 4);
    }
    return (0);
}

int	ft_check_sort_n(t_list *a, t_list *b, int n)
{
	int	count;
	int	len;

	count = 0;
	len = ft_lstlen(a);
	// printf("len : %d\n", len);
	// printf("%d %d\n", (a)->index, (b)->index);
	if (len == 1)
		return (2);
    if (len > 1)
	{
        while (a->next && n > 0)
	    {
	    	if (a->content <= a->next->content && a->next)
	    		count++;
	    	a = a->next;
           n--;
	    }
	    if (count == len - 1 && !b)
	    	return (1);
	    if (count == len - 1)
	    	return (2);
    }
	return (0);
}

int	ft_check_sortb(t_list *a, int n)
{
	int	count;
	int	len;

	count = 0;
	len = n;
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->content >= a->next->content && a->next)
			count++;
		a = a->next;
	}
	if (count == len - 1)
		return (2);
	return (0);
}

int	ft_check_sortn(t_list *a, int len)
{
	int	count;
	int	n;

	count = 0;
	n = len;
	if (ft_lstlen(a) > 2)
	{
		while (a->next && n > 0)
		{
		   	if (a->content <= a->next->content && a->next)
		   		count++;
		   	a = a->next;
 	       n--;
		}
		if (count == len)
			return (1);
	}	
	return (0);
}

int	ft_find_lstindex(t_list *lst, int start, int end)
{
	int	index;

	index = 1;
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->index >= start && lst->index <= end)
			return (index); 
		lst = lst->next;
		index++;
	}
	return (index);
}
