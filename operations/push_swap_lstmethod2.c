/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lstmethod2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:21:44 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/24 20:27:49 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
