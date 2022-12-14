/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:21:46 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/03 17:55:19 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_lines(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	str = (char *)malloc(i + 1);
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
	{
		free(lines);
		return (0);
	}
	while (lines[i] && lines[i] != '\n')
		i++;
	if (lines[i] == '\n')
		i++;
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
	while (!ft_strrchr(save, '\n') && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
		{
			free(save);
			free(buff);
			return (0);
		}
		buff[bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[300];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 300)
		return (0);
	save[fd] = read_fd(fd, save[fd]);
	if (!save[fd])
	{
		free(save[fd]);
		return (0);
	}
	line = get_lines(save[fd]);
	save[fd] = save_next_line(save[fd]);
	return (line);
}
