/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:17 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/23 18:33:36 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_fd(int fd)
{
	static char		*line;
	static size_t	count;

	count = BUFFER_SIZE;
	while (0 <= --count && fd != '\n')
		read(fd, ft_strdup(line), sizeof(char));
	return (line);
	return (0);
}
static int	count_lines(int count)
{
	static unsigned int	numbytes;
	static char			*saved;
	static size_t		buffer;
	ft_strdup(saved);
	numbytes = read(fd, &saved, sizeof(char));
	while (numbytes > 0 && BUFFER_SIZE < )
	read(fd, &saved, numbytes);
}

char	*get_next_line(int fd)
{
	if (fd == '\n')
	{
		
	}
	line =
}