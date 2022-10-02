/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_formatinput.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:23:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/24 20:31:13 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_input(char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		free(num[i]);
		i++;
	}
	free(num);
}

void	error_handling(t_list **lst, char **split)
{
	if ((*lst))
		ft_lstnumclear(lst);
	if (split)
		free_input(split);
	write(2, "Error\n", 6);
	exit(0);
}

void	create_stack_a(char **split, char *num, t_list **lst, int i)
{
	t_list	*a1;

	if (!check_digit(num))
		error_handling(lst, split);
	a1 = ft_intlst_new(ft_atoi(num), i);
	ft_add_lst(lst, a1);
}

void	format_input(char **input, int argc, t_list **lst)
{
	int		i;
	int		j;
	char	**num_split;

	i = 1;
	num_split = NULL;
	while (i < argc)
	{
		num_split = ft_split(input[i], ' ');
		j = 0;
		while (num_split[j])
		{
			create_stack_a(num_split, num_split[j], lst, i);
			j++;
		}
		free_input(num_split);
		i++;
	}
	num_split = NULL;
	if (!check_input(*lst))
		error_handling(lst, num_split);
}

void	add_index(t_list **stack_a)
{
	t_list	*a;
	size_t	len;
	int		i;

	i = 0;
	len = ft_lstlen(*stack_a);
	a = *stack_a;
	while (i < (int)len)
	{
		a->index = ft_count_compare(*stack_a, a, len) + 1;
		a = a->next;
		i++;
	}
}
