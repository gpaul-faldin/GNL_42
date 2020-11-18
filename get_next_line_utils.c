/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:14:40 by gpaul             #+#    #+#             */
/*   Updated: 2020/11/18 18:16:27 by gpaul            ###   ########.fr       */
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

char	*ft_strndup(char *s1, int i)
{
	int		size;
	char	*s2;
	int		n;

	n = 0;
	size = ft_strlen((char*)s1);
	if (size <= i)
	{
		free(s1);
		s1 = NULL;
		return (0);
	}
	//printf("I dup == %d\n", i);					/////////////
	if (!(s2 = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (n < size - 1)
	{
		s2[n] = s1[n + i];
		n++;
	}
	s2[n] = '\0';
	printf("S2 == %s\n", s2);
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		n;

	i = 0;
	n = 0;

	free(s1);
	s1 = NULL;
	if (!(re = malloc(sizeof(char) * (ft_strlen(s2) + 1))))
		return (0);
	while (s1 != NULL && i < ft_strlen(s1))
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
	//printf("S1 == %s\nS2 == %s\n", s1, s2);					//////////////////
	return (re);
}
