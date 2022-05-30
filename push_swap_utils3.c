/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:31:11 by npiya-is          #+#    #+#             */
/*   Updated: 2022/05/30 18:23:32 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_intlst_new(int content, int index);

int	ft_check_sort(t_list *a, t_list *b)
{
	int	count;
	int	len;

	count = 0;
	len = ft_lstlen(a);
	while (a->next)
	{
		if (a->content <= a->next->content && a->next)
			count++;
		a = a->next;
	}
	if (count == len - 1 && !b)
		return (1);
	if (count == len - 1)
		return (2);
	return (0);
}

t_list	*ft_find_max(t_list *a, int n)
{
	t_list	*lstmax;
	int	max;

	max = 0;
	lstmax = NULL;
	while (a && n)
	{
		if (a->content > max)
		{
			lstmax = a;
			max = a->content;
		}
		a = a->next;
		n--;
	}
	return (lstmax);
}

int	ft_find_maxn(t_list *a, int n)
{
	int	i;	

	i = 0;
	while (a->index != n)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int	ft_find_minn(t_list *a, int n)
{
	int	i;	

	i = 0;
	while (a->index != 1 && i <= n)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_list	*ft_find_min(t_list *a, int n)
{
	t_list	*min;

	min = a;
	while (a && n)
	{
		if (min->content > a->content)
			min = a;
		a = a->next;
		n--;
	}
	return (min);
}

int	ft_maxindex(t_list *a, t_list *max)
{
	int	i;

	i = 0;
	while (a && a->content != max->content)
	{
		a = a->next;
		i++;
	}
	return (++i);
}

int	ft_minindex(t_list *a, t_list *min)
{
	int	i;

	i = 0;
	while (a && a->content != min->content)
	{
		a = a->next;
		i++;
	}
	return (++i);
}

t_list	*ft_find_lstat(t_list *lst, int n)
{
	if (!lst || !n)
		return (NULL);
	while (n)
	{
		lst = lst->next;
		n--;
	}
	return (lst);
}

void	ft_show_ab(t_list *a, t_list *b)
{
	printf("---------------------------------------");
	printf("\na	b\n");
	while (a || b)
	{
		if (a)
		{
			printf("%d ", a->content);
			printf("%d", a->index);
			a = a->next;
		}
		printf("	");
		if (b)
		{
			printf("%d ", b->content);
			printf("%d", b->index);
			b = b->next;
		}
		printf("\n");
	}
	printf("---------------------------------------");
	printf("\n");
}
