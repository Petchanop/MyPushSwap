/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lstmethod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:21:14 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/24 20:27:31 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_intlst_new(long content, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	ft_add_lst(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		lst = &tmp;
	}
	else
		*lst = new;
}

void	ft_add_lstfront(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = NULL;
	if (new)
	{
		tmp = *lst;
		*lst = new;
		(*lst)->next = tmp;
	}
}

size_t	ft_lstlen(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
