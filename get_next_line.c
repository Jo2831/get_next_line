/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:10:21 by ytapano           #+#    #+#             */
/*   Updated: 2023/11/30 16:31:11 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_full_str(int fd, char *store)
{
	char	*str;
	int		rd;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	rd = 1;
	while (ft_strchr(store, '\n') == 0 && rd != 0)																																								
	{
		rd = read(fd, str, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			return (NULL);
		}
		str[rd] = '\0';
		store = ft_strjoin(store, str);
	}
	free(str);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*stor;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	stor = ft_full_str(fd, stor);
	if (!stor)
		return (NULL);
	line = ft_get_line(stor);
	stor = ft_get_remain(stor);
	return (line);
}

int main()
{																															
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
	
	while ((line = get_next_line(fd)))																												
	{
		printf("buf -> 5 %s\n", line);
		free(line);
	}
	return (0);
}