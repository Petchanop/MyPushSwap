/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:39:23 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/29 00:06:28 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss_sa_sb(char *input, t_list **a, t_list **b)
{
	if (!ft_strncmp(input, "sa\n", 3))
		ft_swap_ab(*a);
	else if (!ft_strncmp(input, "sb\n", 3))
		ft_swap_ab(*b);
	else if (!ft_strncmp(input, "ss\n", 3))
		ft_swap_bothab(*a, *b);
	else
		return (0);
	return (1);
}

int	rr_ra_rb(char *input, t_list **a, t_list **b)
{
	if (!ft_strncmp(input, "ra\n", 3))
		ft_rotate_lst(*a);
	else if (!ft_strncmp(input, "rb\n", 3))
		ft_rotate_lst(*b);
	else if (!ft_strncmp(input, "rr\n", 3))
		ft_rotate_all(*a, *b);
	else
		return (0);
	return (1);
}

int	rrr_rra_rrb(char *input, t_list **a, t_list **b)
{
	if (!ft_strncmp(input, "rra\n", 4))
		ft_reverse_rotate(a, b);
	else if (!ft_strncmp(input, "rrb\n", 4))
		ft_reverse_rotate(b, a);
	else if (!ft_strncmp(input, "rrr\n", 4))
		ft_reverse_all(a, b);
	else
		return (0);
	return (1);
}

int	pa_pb(char *input, t_list **a, t_list **b)
{
	if (!ft_strncmp(input, "pa\n", 3))
		ft_push_pab(a, b);
	else if (!ft_strncmp(input, "pb\n", 3))
		ft_push_pab(b, a);
	else
		return (0);
	return (1);
}
