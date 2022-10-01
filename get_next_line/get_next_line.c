/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:17 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/01 16:18:48 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *arg)
{
	size_t	size;

	size = 0;
	if (arg[size] == 0)
		return (0);
	while (arg[size])
		size++;
	return (size);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if ((dst == src) || n == 0)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[a];
		i++;
		a++;
	}
	n = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	else
		ft_memcpy(str, s1, ft_strlen(s1));
	*(str + len) = '\0';
	return (str);
}

char	*ft_strrchr(const char *str, int c)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	while (0 <= a)
	{
		if (str[a] == (char)c)
			return ((char *)str + a);
		a--;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	a;
	char	*str;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	a = 0;
	while (s1[i])
		str[a++] = s1[i++];
	i = 0;
	while (s2[i])
		str[a++] = s2[i++];
	str[a] = '\0';
	return (str);
}

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

int	main(void)
{
	int		fd;
	char	*print;

	fd = open("variable_nls.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	return (0);
}
