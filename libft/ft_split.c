/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:23:52 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/20 07:46:18 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_string(char const *s, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (*s)
	{
		if (a == 0)
		{
			a = 1;
			i++;
		}
		else if (*s == c)
			a = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	
	int		index;
	char	**split;

	j = 0;
	//split[j] = (char *)malloc((count_string(s, c) + 1) * sizeof(char *));
	if (!s)
		return (0);
	i = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && 0 <= index)
		{
			split[j][k++] = ft_substr(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/* 
int main ()
{
	char	str[] = "Hello World cruel!";
	char	c = 32;

	ft_split(str, c);
	printf("%s", str);
} */
