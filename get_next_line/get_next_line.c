/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:17 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/26 00:17:48 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_fd(int fd, char *saved)
{
	char	*buff;
	int		bytes;
	buff = malloc(BUFFER_SIZE + 1 * (sizeof(char)));
	if (!buff)
		return (NULL);
	while (!ft_strrchr(saved, '\n') || bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		saved = ft_strjoin(saved, buff);

	}
	free(buff);
	return (saved);
}
static char	ft_lines(char *saved)
{
	int		i;
	char	*s;

	if (!saved)
		return (NULL);
	i = -1;
	while (saved[i] && saved[i - 1] == '\n')
	{
		if (saved[i] == '\n')
			ft_strdup(saved);

	}
}

char	*get_next_line(int fd)
{
	if (fd == '\n')
	{
		
	}
	line =
}