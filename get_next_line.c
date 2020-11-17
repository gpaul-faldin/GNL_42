/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:14:41 by gpaul             #+#    #+#             */
/*   Updated: 2020/11/17 18:00:19 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		next_nl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	else
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
	if ((*line = malloc(sizeof(char) * size + 1)) == NULL)
			return ;
	while (i < size)
	{
		*(*line + i) = *(*cache + i);
		i++;
	}
	*(*line) = '\0';
	
}

int		get_next_line(int fd, char **line)
{
	static char		*cache = NULL;
	char			buf[BUFFER_SIZE + 1];
	int				re;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
		write(1, "salut\n", 6);			////////////
	while ((re = read(fd, buf, BUFFER_SIZE)) == BUFFER_SIZE)
	{
		//write(1, "caca\n", 5);			////////////
		buf[re] = '\0';
		printf("PRINTF = %s\n", buf);
		//write(1, "caca\n", 5);			////////////
		cache = ft_strjoin(cache, buf);
		//printf("%s\n", cache);			////////////
		if (next_nl(cache) != 0)
		{
			ft_fill_line(&cache, line);
			return (1);
		}
	}
	return (0);
}

//////////////////////////////////////////////////////
int			main(int argc, char **argv)
{
	char	**line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	line = malloc(sizeof(char**) * 10);
	(void)argc;

	printf("%d\n", get_next_line(fd, line));
}
