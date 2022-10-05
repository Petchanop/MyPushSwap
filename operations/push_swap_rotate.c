/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:11:47 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/05 18:48:25 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst);

size_t	ft_lstlen(t_list *lst);

void	ft_rotate_lst(t_list *a)
{
	t_list	*tmp;
	size_t	len;
	int		temp;
	int		index;

	tmp = NULL;
	len = 0;
	index = 0;
	if (a)
	{	
		len = ft_lstlen(a);
		tmp = a;
		while (len > 1)
		{
			temp = tmp->content;
			index = tmp->index;
			tmp->content = tmp->next->content;
			tmp->index = tmp->next->index;
			tmp->next->content = temp;
			tmp->next->index = index;
			tmp = tmp->next;
			len--;
		}
	}
}

void	ft_rotate_all(t_list *a, t_list *b)
{
	if (a && b)
	{
		ft_rotate_lst(a);
		ft_rotate_lst(b);
	}
}

void	ft_write_rr(t_list *a, t_list *b)
{
	ft_rotate_all(a, b);
	write(1, "rr\n", 3);
}
