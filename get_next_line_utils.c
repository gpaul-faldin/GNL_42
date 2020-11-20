/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:14:40 by gpaul             #+#    #+#             */
/*   Updated: 2020/11/20 14:22:12 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char	*str)
{
	int		i;

	i = 0;
	if (!str || str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *s1, int i)
{
	int		size;
	char	*re;
	int		n;
	int		x;

	x = 0;
	n = 0;
	size = ft_strlen(s1);
	if (size <= i && !s1)
	{
		free(s1);
		s1 = NULL;
		return (0);
	}
	if (!(re = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		re[n] = s1[i];
		n++;
		i++;
	}
	re[n] = '\0';
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	return (re);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!(re = malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (i < ft_strlen(s1))
	{
		re[i] = s1[i];
		i++;
	}
	while (n < ft_strlen(s2))
	{
		re[i + n] = s2[n];
		n++;
	}
	re[i + n] = '\0';
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	return (re);
}
