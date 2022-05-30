/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:40:03 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/09 19:31:38 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}

t_list	*ft_intlst_new(int content, int index)
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
		*lst  = new;
		new->next = tmp;
	}
}

void	ft_dellst(t_list **lst)
{
	if (*lst)
		*lst = (*lst)->next;
}

size_t	ft_lstlen(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
