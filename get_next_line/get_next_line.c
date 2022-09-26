/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:17 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/26 15:41:48 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_save_fd(int fd, char *saved)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc(BUFFER_SIZE + 1 * (sizeof(char)));
	if (!buff)
		return (NULL);
	while (!ft_strrchr(saved, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (fd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff = NULL;
		saved = ft_strjoin(saved, buff);
	}
	free(buff);
	return (saved);
}

static char	*get_lines(char *saved)
{
	int		i;
	char	*s;

	if (!saved)
		return (0);
	i = 0;
	s = NULL;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	s = ft_strdup(saved);
	free(saved);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*saved;

	saved = read_save_fd(fd, saved);
	str = cut_lines(saved);
	return (str);

}

int main (void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	printf("que esta leyendo =\n%s", get_next_line(fd));

    return (0);
}