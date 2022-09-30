/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:17 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/30 17:39:12 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_lines(char *line)
{
	int		i;
	char	*str;

	if (!line)
		return (NULL);
	i = 0;
	while (*line && line[i] != '\n')
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*save_next_line(char *lines)
{
	int		i;
	char	*save;
	int		s;

	if (!lines)
		return (NULL);
	i = 0;
	while (lines[i] && lines[i] != '\n')
		i++;
	if (lines[i] == '\n')
		i++;
	save = malloc(ft_strlen(lines) - i + 1);
	if (!save)
		return (0);
	s = 0;
	while (lines[i])
		save[s++] = lines[i++];
	save[s] = '\0';
	return (save);
}

char	*read_fd(int fd, char *save)
{
	char	*buff;
	int		bytes;

	if (!save)
		return (NULL);
	bytes = 1;
	buff = malloc(BUFFER_SIZE + 1);
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			buff = NULL;
		}
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	save = read_fd(fd, save);
	if (!save)
	{
		free(save);
		return (0);
	}
	line = get_lines(save);
	save = save_next_line(save);
	free(save);
	return (line);
}
