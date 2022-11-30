/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:04:25 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/30 15:46:45 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	else
	{
		while (len < ft_strlen(s1))
			str[len++] = s1[i++];
	}
	str[len] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize, t_head *peek)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			if (!(src[i] <= '9' && '0' <= src[i]))
				free_str_list_exit(peek, 0, 0);
			else
				dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

static int	count_string(const char *s, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && check == 0)
		{
			check = 1;
			i++;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (i);
}

char	*ft_substr(char const *s, int start, int len, t_head *peek)
{
	char			*str;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, &s[start], len + 1, peek);
	return (str);
}

char	**ft_split(char const *s, char c, t_head *peek)
{
	int		j;
	int		i;
	int		strt;
	char	**split;

	j = 0;
	i = -1;
	strt = i;
	split = (char **)malloc(sizeof(char *) * (count_string(s, c) + 1));
	if (!split)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && strt < 0)
			strt = i;
		else if (0 <= strt && (s[i] == c || i == ft_strlen(s)))
		{
			split[j++] = ft_substr(s, strt, i - strt, peek);
			strt = -1;
		}
	}
	split[j] = NULL;
	return (split);
}

/* int main(int ac, char **av)
{
	t_head	*peek;
	int 	num;
	int		i;

	peek = ft_addhead();
	if (ac > 1)
	{
		i = 1;
		while (av[i])
		{
			arg_str(&av[i], peek);
			num = ft_atoi(av[i++], peek);
			printf("%d\n", num);
		}
	}
	else
		free_str_list_exit(peek, av, 1);
} */
