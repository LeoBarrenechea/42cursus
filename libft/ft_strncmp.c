/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:31:03 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/08 19:46:58 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			a;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	a = 0;
	if (!n)
		return (0);
	while (str1[a] && str2[a] && str1[a] == str2[a] && a < n - 1)
		a++;
	return (str1[a] - str2[a]);
}

// int	main(void)
// {
// 	const char	str1[] = "abcd";
// 	const char	str2[] = "abcdefghijklmnopqrst";
// 	size_t	n = 6;

// 	printf("%d\n", strncmp(str1, str2, n));
// 	printf("%d", ft_strncmp(str1, str2, n));
// }