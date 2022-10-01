/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:17 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/01 16:23:49 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_lines(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
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

	i = 0;
	if (!lines[i])
		return (0);
	while (lines[i] && lines[i] != '\n')
		i++;
	if (lines[i] == '\n')
		i++;
	save = (char *)malloc(ft_strlen(lines) - i + 1);
	if (!save)
		return (0);
	save = ft_strdup(lines + i);
	free(lines);
	return (save);
}

char	*read_fd(int fd, char *save)
{
	char	*buff;
	int		bytes;

	if (!save)
		save = ft_strdup("");
	bytes = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0)
			break ;
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
	return (line);
}
