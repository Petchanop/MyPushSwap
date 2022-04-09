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

void	ft_print_slst(t_slist *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->num);
		lst = lst->next;
	}
}

t_slist	*ft_intlst_new(int num)
{
	t_slist	*new;

	new = malloc(sizeof(t_slist));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

void	ft_add_slst(t_slist **lst, t_slist *new)
{
	t_slist	*tmp;

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

void	ft_add_slstfront(t_slist **lst, t_slist *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_delslst(t_slist **lst)
{
	if (*lst)
		*lst = (*lst)->next;
}

size_t	ft_slstlen(t_slist *lst)
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
