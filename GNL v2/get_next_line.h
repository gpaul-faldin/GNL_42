/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:59:48 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/05 15:49:16 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif


# include <unistd.h>
# include <stdlib.h>

# include <fcntl.h>
# include <stdio.h>

int		ft_strlen(char	*str);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_alloc(char *s1, int i);


#endif
