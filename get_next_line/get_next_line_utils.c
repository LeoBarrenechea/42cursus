/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:12 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/23 16:37:40 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	**ft_split(char const *s, char c)
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