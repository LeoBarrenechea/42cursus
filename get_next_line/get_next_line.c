/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:17 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/26 15:38:31 by lbarrene         ###   ########.fr       */
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