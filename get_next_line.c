/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:14:41 by gpaul             #+#    #+#             */
/*   Updated: 2020/11/20 14:22:25 by gpaul            ###   ########.fr       */
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
	while (i < size)
	{
		*((*line) + i) = *((*cache) + i);
		i++;
	}
	*((*line) + size) = '\0';
	*cache = ft_strndup(*cache, next_nl(*cache));
}

int		get_next_line(int fd, char **line)
{
	static char		*cache = NULL;
	char			buf[BUFFER_SIZE + 1];
	int				re;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if ((next_nl(cache) > 0))
	{
		ft_fill_line(&cache, line);
		//printf("line CACHE == %s\n", *line);
		return (1);
	}
	while ((re = read(fd, buf, BUFFER_SIZE)) == BUFFER_SIZE)
	{
		buf[re] = '\0';
		cache = ft_strjoin(cache, buf);
		if (next_nl(buf) > 0)
		{
			ft_fill_line(&cache, line);
			//printf("line == %s\n", *line);
			return (1);
		}
	}
	if (re > 0)
	{
		buf[re] = '\0';
		cache = ft_strjoin(cache, buf);
		if (next_nl(cache) == 0)
		{
			*line = ft_strndup(cache, next_nl(cache));
			return (0);
		}
		ft_fill_line(&cache, line);
		//printf("line RE == %s\n", *line);
		return (1);
	}
	return (0);
}
