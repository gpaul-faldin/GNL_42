/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:00:40 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/04 15:46:18 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		next_nl(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		return (i + 1);
		i++;
	}
	return (0);
}

void	ft_fill_line(char **cache, char **line)
{
	int		i;
	int		size;

	i = 0;
	if (next_nl(*cache) > 0)
		size = next_nl(*cache);
	else
		size = ft_strlen(*cache);
	if ((*line = malloc(sizeof(char*) * size + 1)) == NULL)
		return ;
	while (i < size - 1)
	{
		*((*line) + i) = *((*cache) + i);
		i++;
	}
	*((*line) + i) = '\0';
	*cache = ft_alloc(cache, next_nl(*cache));
}

int		ft_return(int re, char *cache, char **line)
{
	if (re == 0)
		return (0);
	else
		ft_fill_line(&cache, line);
		printf ("re == %s\n", *line);
	return(1);
}

int		get_next_line(int fd, char **line)
{
	static char		*cache;
	char			buf[BUFFER_SIZE + 1];
	int				re;
	
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	while ((re = read(fd, buf, BUFFER_SIZE)) == BUFFER_SIZE)
	{
		buf[re] = '\0';
		cache = ft_strjoin_free(cache, buf);
		if (next_nl(cache) > 0)
			return(ft_return(re, cache, line));
	}
	if (next_nl(cache) > 0)
		return(ft_return(re, cache, line));
	return (0);
}
