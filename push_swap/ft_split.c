/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:04:25 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/01 17:52:29 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_addnew(int arg)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new -> num = arg;
		new -> next = NULL;
	}
	return (new);
}

int	ft_strlen(const char *arg)
{
	int	size;

	size = 0;
	if (arg[size] == 0)
		return (0);
	while (arg[size])
		size++;
	return (size);
}

void	write_error_exit(void)
{
	write (1, "Error\n", 6);
	exit (-1);
}

void	free_str_list_exit(t_head *list, char **str, int len)
{
	int		i;
	t_list	*del;

	if (str)
	{
		i = 0;
		while (str[i])
			free (str[i++]);
		free (str);
	}
	if (list)
	{
		while (list->peek)
		{
			del = list->peek;
			list->peek = list->peek->next;
			free (del);
		}
		free (list);
		list = NULL;
	}
	if (len == 0)
		write_error_exit();
}

int	ft_atoi(char *str, t_head *ptr)
{
	int			i;
	int			sign;
	long		num;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] <= 13 && 9 <= str[i]) || (str[i] == 32))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] != 48))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] <= '9' && '0' <= str[i]) || str[i] == 32)
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	if ((num * sign) <= INT_MIN || INT_MAX <= (num * sign))
		free_str_list_exit(ptr, 0, 0);
	return (num * sign);
}

void	ft_insertend(t_head *head, int arg)
{
	t_list	*aux;
	t_list	*new;

	new = ft_addnew(arg);
	if (head->peek == NULL)
		head->peek = new;
	else
	{
		aux = head->peek;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	head->len++;
}

t_head	*ft_addhead(void)
{
	t_head	*peek;

	peek = (t_head *)malloc(sizeof(t_head));
	if (!peek)
		return (0);
	peek->peek = NULL;
	peek->len = 0;
	return (peek);
}

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
			if ((src[i] <= '9' && '0' <= src[i])
				|| ((src[i] == '-' || src[i] == '+') && (i == 0)))
				dst[i] = src[i];
			else
				free_str_list_exit(peek, 0, 0);
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

void check_insert(char *av, t_head *peek)
{
	int	num;

	num = ft_atoi(av, peek);
	check_dup(peek, num, &av);
	ft_insertend(peek, num);
}

t_head	*ft_full_list(int ac, char **av)
{
	t_head	*peek;
	char	**str;
	int		i;

	peek = ft_addhead();
	str = NULL;
	i = 0;
	if (2 < ac)
	{
		while (*++av)
		{
			check_num(*av, peek);
			check_insert(*av, peek);
		}
	}
	else if (2 == ac && *++av)
	{
		str = ft_split(*av, ' ', peek);
		while (str[i])
			check_insert(str[i++], peek);
	}
	free_str_list_exit(0, str, 1);
	return (peek);
}

int main (int ac, char **av)
{
	t_head	*peek;

	peek = ft_full_list(ac, av);
	printf("%d", peek->peek->num);
}
