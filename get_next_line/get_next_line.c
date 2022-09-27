/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:17 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/27 15:36:39 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 char	*read_save_fd(int fd, char *saved)
{
	char		*buff;
	int			bytes;

	buff = (char *)malloc(BUFFER_SIZE + 1 * (sizeof(char)));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strrchr(buff, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		saved = ft_strjoin(buff, saved);
	}
	free(buff);
	return (saved);
}

char	*get_lines(char *saved)
{
	int		i;
	char	*s;
	int		init;

	if (!saved)
		return (0);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * i + 2);
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
	int		end;

	init = 0;
	end = 0;
	while (*saved && saved[init] != '\n')
		init++;
	if (saved[init] == '\n')
		init++;
	len_saved = ft_strlen(saved);
	rest = (char *)malloc(sizeof(char) * (len_saved - init) + 1);
	if (!rest)
		return (NULL);
	if (len_saved <= BUFFER_SIZE && saved[init] != '\0')
		rest = ft_strdup(saved + init);
	while (BUFFER_SIZE < len_saved
		&& (end < BUFFER_SIZE || saved[init] != '\0'))
		rest[end++] = saved[init++];
	return (rest);
}

/* char	*get_next_line(int fd)
{
	static char	*str;
	char		*saved;
	int			i;
	char		*rest;

} */

int main (void)
{
	int		fd;
	char	*saved;

	fd = open("test.txt", O_RDONLY);
	saved = "hola\n com\0o estas todo te va bien!";
	printf("que esta leyendo =\n%s", line_save(saved));
    return (0);
}