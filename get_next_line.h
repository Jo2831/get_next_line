/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:02:58 by ytapano           #+#    #+#             */
/*   Updated: 2023/11/30 16:41:17 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
#include <stdio.h>

char	*ft_get_remain(char *left);
char	*ft_full_str(int fd, char *store);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *all);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);

#endif