/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:55:34 by gpaul             #+#    #+#             */
/*   Updated: 2020/11/19 18:42:07 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int		get_next_line(int fd, char **line);

int			main(int argc, char **argv)
{
	char	*line = 0;
	int		fd;
	int		i = 0;

	fd = open(argv[1], O_RDONLY);
	(void)argc;

	while (i < 25)
	{
		printf("%d\n", get_next_line(fd, &line));
		i++;
	}
}
