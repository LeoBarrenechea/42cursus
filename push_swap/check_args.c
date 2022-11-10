/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:57:53 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/10 16:14:13 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
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

char	**ft_split(char *s, char c)
{
	int		j;
	int		i;
	int		slen;
	int		strt;
	char	**split;

	j = 0;
	i = -1;
	strt = i;
	slen = ft_strlen(s);
	split = (char **)malloc(sizeof(char *) * (count_string(s, c) + 1));
	if (!split)
		return (NULL);
	while (++i <= slen)
	{
		if (s[i] != c && strt < 0)
			strt = i;
		else if (0 <= strt && (s[i] == c || i == slen))
		{
			split[j++] = ft_substr(s, strt, i - strt);
			strt = -1;
		}
	}
	split[j] = NULL;
	return (split);
}

t_stak	*ft_addnew(int arg)
{
	t_stak	*new;

	new = (t_stak *)malloc(sizeof(t_stak));
	if (new != NULL)
	{
		new -> num = arg;
		new -> next = NULL;
	}
	return (new);
}

void	ft_insertend(t_head *peek, int arg)
{
	t_stak	*aux;
	t_stak	*new;

	new = ft_addnew(arg);
	if (peek->peek == NULL)
		peek->peek = new;
	else
	{
		aux = peek->peek;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	peek->etail = new;
	peek->len++;
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	num;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] <= 13 && 9 <= str[i]) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] <= '9' && '0' <= str[i]))
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	if (num <= INT_MIN || INT_MAX <= num)
	{
		write (1, "Error\n", 6);
		free_stack(&peek);
	}
	return (num * sign);
}

t_head	*ft_addheader(void)
{
	t_head	*peek;

	peek = (t_head *)malloc(sizeof(t_head));
	peek->len = 0;
	peek->peek = NULL;
	return (peek);
}
int	check_num(char *av)
{
	int	i;

	i = 0;
	while (*av && (av[i] < 58 && 47 < av[i] || av[i] == 32 || av[i] == '-'))
		i++;
	if (av[i] == '\0')
		return (1);
	return (0);
}

void	arg_str(char **av, t_head *peek)
{
	 int	num;

	av = ft_split(*av, ' ');
	while (*av)
	{
		num = ft_atoi(*av);
		ft_insertend(peek, num);
		av++;
	}
}

void	free_stack(void *list)
{
	list = NULL;
	free(list);
}

int main(int ac, char **av)
{
	int		i;
	t_head	*peek;

	peek = ft_addheader();
	if (ac == 2)
	{
		if (av[1] && (check_num(av[1]) == 1))
			arg_str(&av[1], peek);
		else
		{
			write (1, "Error\n", 6);
			free_stack(peek);
		}
	}
	i = 0;
	while (peek->peek)
	{
		printf("[%i]  |  [%d]\n", i, peek->peek->num);
		peek->peek = peek->peek->next;
		i++;
	}
}
