/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:21:51 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/20 17:15:41 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (ft_isdigit(num[i]))
		i++;
	if (num[i])
		return (0);
	return (1);
}

int	check_double(t_list *lst1, t_list *lst2)
{
	int	num;
	int track;
	t_list	*tmp;

	tmp = lst2;
	while (lst1)
	{
		num = lst1->content;
		track = 0;
		while (tmp)
		{
			if (num == tmp->content)
				track++;
			tmp = tmp->next;
		}
		if (track > 1)
			return (0);
		tmp = lst2;
		lst1 = lst1->next;
	}
	return (1);
}