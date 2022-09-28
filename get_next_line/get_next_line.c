/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:17 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/28 15:35:01 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_save_fd(int fd, char *saved)
{
	char	*buff;
	int		bytes;

	if (!saved)
		saved = (char *)malloc(1);
	buff = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strrchr(saved, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		saved = ft_strjoin(saved, buff);
	}
	free(buff);
	return (saved);
}

char	*get_lines(char *saved)
{
	int		i;
	char	*s;

	if (!saved)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		s[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		s[i] = saved[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*line_save(char *saved)
{
	int		init;
	char	*rest;
	int		len_saved;

	init = 0;
	while (saved[init] && saved[init] != '\n')
		init++;
	if (saved[init])
	{
		free(saved);
		return (NULL);
	}
	len_saved = ft_strlen(saved);
	rest = (char *)malloc(sizeof(char) * len_saved - init + 1);
	if (!rest)
		return (NULL);
	init++;
	rest = ft_strdup(saved + init);
	free(saved);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (0);
	saved = read_save_fd(fd, saved);
	if (!saved)
		return (NULL);
	line = get_lines(saved);
	saved = line_save(saved);
	return (line);
}
