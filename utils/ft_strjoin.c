/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:42:13 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/28 23:47:56 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char const *str);

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	str[i + ft_strlen(s1)] = '\0';
	free(s1);
	return (str);
}
