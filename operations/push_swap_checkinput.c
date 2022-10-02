/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkinput.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:21:51 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/03 01:37:17 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
			exit(0);
		i++;
	}
}

void	check_int(long num, t_list *lst)
{
	if (num < -2147483648 || num > 2147483647)
	{
		ft_lstnumclear(&lst);
		write(2, "Error\n", 6);
		exit(0);
	}
}

int	check_digit(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	if (num[i] == '0' && ft_isdigit(num[i + 1]))
		return (0);
	while (ft_isdigit(num[i]))
		i++;
	if (num[i] || !ft_isdigit(num[i - 1]))
		return (0);
	return (1);
}

int	check_double(t_list *lst1, t_list *lst2)
{
	int		num;
	int		track;
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

int	check_input(t_list *lst)
{
	int		len;
	t_list	*tmp;

	len = ft_lstlen(lst);
	tmp = lst;
	while (tmp)
	{
		check_int(tmp->content, lst);
		tmp = tmp->next;
	}
	if (!check_double(lst, lst))
		return (0);
	if (len == 1)
	{
		ft_lstnumclear(&lst);
		exit(0);
	}
	return (1);
}
