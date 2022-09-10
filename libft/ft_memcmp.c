/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:54:02 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/10 12:07:18 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			a;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	a = 0;
	while (str1[a] == str2[a] && a < n - 1)
		a++;
	return (str1[a] - str2[a]);
}

// int	main(void)
// {
// 	const char	str1[] = "atoms\0\0\0\0";
// 	const char	str2[] = "atoms\0abc";
// 	int	n = 8;

// 	printf("%d\n", memcmp(str1, str2, n));
// 	printf("%d", ft_memcmp(str1, str2, n));
// }