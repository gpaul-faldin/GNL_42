/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:55:34 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/06 00:17:15 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int		get_next_line(int fd, char **line);

int			main(int argc, char **argv)
{
	char	*line = 0;
	int		fd;
	int		i = 1;

	fd = open(argv[1], O_RDONLY);
	(void)argc;

	while (i != 0)
	{
		i = get_next_line(fd, &line);
		printf("%d\n", i);
	}
}
