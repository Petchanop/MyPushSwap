/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_readinput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:49:52 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/05 18:47:14 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_input(void)
{
	int		rd;
	int		buffer_size;
	char	*input;
	char	*command;

	rd = 1;
	buffer_size = 1;
	command = malloc((buffer_size) * sizeof(char));
	input = malloc((buffer_size + 1) * sizeof(char));
	if (!input || !command)
		return (NULL);
	input[1] = '\0';
	command[0] = '\0';
	while (rd)
	{
		rd = read(0, input, buffer_size);
		command = ft_strjoin(command, input);
		if (input[0] == '\n')
			break ;
	}
	free(input);
	return (command);
}

int	compare_input(char *input, t_list **a, t_list **b)
{
	if (ss_sa_sb(input, a, b))
		return (1);
	if (rr_ra_rb(input, a, b))
		return (1);
	if (rrr_rra_rrb(input, a, b))
		return (1);
	if (pa_pb(input, a, b))
		return (1);
	else
		return (0);
}

void	read_operations(t_list **a, t_list **b)
{
	char	*input;
	int		lena;

	lena = ft_lstlen(*a);
	while (1)
	{
		input = read_input();
		if (compare_input(input, a, b))
		{
			if (ft_check_sortn(*a, lena) == 1)
				break ;
		}
		else
		{
			write(1, "Error\n", 6);
			ft_lstnumclear(&a);
			ft_lstnumclear(&b);
			exit(0);
		}
		free(input);
	}
}
