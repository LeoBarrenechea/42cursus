/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:23:52 by lbarrene          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2022/09/23 22:47:15 by lbarrene         ###   ########.fr       */
=======
/*   Updated: 2022/10/25 19:00:32 by lbarrene         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
=======
/*   Updated: 2022/11/11 17:22:22 by lbarrene         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

<<<<<<< HEAD
char	**ft_split(char const *s, char c)
=======
char	**ft_split(char *s, char c)
>>>>>>> refs/remotes/origin/main
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
		free (*split);
	}
	split[j] = NULL;
	return (split);
}
