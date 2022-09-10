/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:44:44 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/10 17:41:21 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

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

int main(void)
{
	char	str1[] = "hello everyone!";
	char	str2[] = "hello ";
	size_t	n = 15;

	printf("%s\n", ft_strnstr(str1, str2, n));
	printf("%s", strnstr(str1, str2, n));

}