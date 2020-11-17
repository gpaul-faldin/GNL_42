/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:14:40 by gpaul             #+#    #+#             */
/*   Updated: 2020/11/17 14:45:26 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char	*str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s2;
	int		i;

	i = 0;
	size = ft_strlen((char*)s1);
	if (!(s2 = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!(re = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i])
	{
		re[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		re[i + n] = s2[n];
		n++;
	}
	if (*s1)
	{
		free(s1);
		s1 = NULL;
	}
	re[i + n] = '\0';
	return (re);
}
