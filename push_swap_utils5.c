/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:43:49 by npiya-is          #+#    #+#             */
/*   Updated: 2022/05/28 23:11:31 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_rotate(t_list **a, t_queue n)
{
    int count;
    int countr;

    countr = 0;
    count = n.range; 
    if (*a)
    {
        while (*a)
        {
            if ((*a)->index > n.end || (*a)->index < n.start)
                countr++;
            (*a) = (*a)->next;
        }
    }
    return (countr);
}

int count_reverse(t_list **a, t_queue n)
{
    int count;
    int countrr;
    int len;

    countrr = 0;
    count = n.range;
    len = ft_lstlen(*a) - 1;
    while (len)
    {
        if ((*a)->index <= n.end)
        {
            count--;
            if (!count)
                break;
        }
        countrr++;
        len--;
    }
    return (countrr);
}

int rr_or_rrr(t_list **a, t_list **b, t_queue n)
{
   
    
       

        }
    }
}