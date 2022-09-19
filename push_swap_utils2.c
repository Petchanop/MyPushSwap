/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:15:58 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/19 22:29:40 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_lstlen(t_list *lst);

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = NULL;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		last = lst;
	}
	return (last);
}

void	ft_lstnumclear(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
}

t_list	*ft_find_lst(t_list *lst)
{
	size_t	half;

	if (!lst)
		return (NULL);
	half = ft_lstlen(lst) / 2;
	while (half)
	{
		lst = lst->next;
		half--;
	}
	return (lst);
}

int	ft_count_compare(t_list *a, t_list *a1, int n)
{
	t_list	*tmp;
	int	count;

	tmp = a;
	count = 0;
	while (tmp && n)
	{
		if (a1->content > tmp->content)
			count++;
		tmp = tmp->next;
		n--;
	}
	return (count);
}