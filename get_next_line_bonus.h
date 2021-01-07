/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:14:36 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/07 16:03:09 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int		next_nl(char *str);
int		ft_strlen(char	*str);
char	*ft_strndup(char **s1, int i);
char	*ft_strjoin(char **s1, char *s2);
int		get_next_line(int fd, char **line);




#endif
