/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:23:52 by lbarrene          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/20 07:46:18 by lbarrene         ###   ########.fr       */
=======
/*   Updated: 2022/09/20 13:35:01 by lbarrene         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static int	count_string(char const *s, char c)
=======
static int	count_string(const char *s, char c)
>>>>>>> refs/remotes/origin/main
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (*s)
	{
<<<<<<< HEAD
		if (a == 0)
=======
		if (*s != c && check == 0)
>>>>>>> refs/remotes/origin/main
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

char	**ft_split(char const *s, char c)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> refs/remotes/origin/main
	{
		if (s[i] != c && strt < 0)
			strt = i;
		else if (0 <= strt && (s[i] == c || i == slen))
		{
<<<<<<< HEAD
			split[j][k++] = ft_substr(s, index, i);
			index = -1;
=======
			split[j++] = ft_substr(s, strt, i - strt);
			strt = -1;
>>>>>>> refs/remotes/origin/main
		}
	}
	split[j] = NULL;
	return (split);
}
<<<<<<< HEAD
/* 
int main ()
{
	char	str[] = "Hello World cruel!";
	char	c = 32;

	ft_split(str, c);
	printf("%s", str);
} */
=======
>>>>>>> refs/remotes/origin/main
