/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:44:44 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/12 18:57:48 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return ((char *)haystack);
	while (((char *)haystack)[i] != '\0' && i < len)
	{
		a = 0;
		while (((char *)haystack)[i + a] && needle[a]
			&& ((char *)haystack)[i + a] == needle[a] && i + a < len)
			a++;
		if (a == n_len)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
