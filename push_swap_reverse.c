/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:52:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/19 23:01:23 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_intlst_new(int num, int index);

t_list	*ft_lstlast(t_list *lst);

size_t	ft_lstlen(t_list *lst);

void	ft_dellst(t_list **lst);

void	ft_add_lstfront(t_list **lst, t_list *new);

void	ft_reverse_rotate(t_list **a)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*del;

	head = NULL;
	tmp = NULL;
	if (*a)
	{
		tmp = ft_lstlast(*a);
		head = ft_intlst_new(tmp->content, tmp->index);
		ft_add_lstfront(a, head);
		tmp = *a;
		while (tmp->next != NULL)
		{
			del = tmp;
			tmp = tmp->next;
		}
		del->next = NULL;
		free(tmp);
	}
}

void	ft_reverse_all(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
