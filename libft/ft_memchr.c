/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:43:09 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/08 20:25:18 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;

	a = 0;
	while (a < n)
	{
		if (((unsigned char *)s)[a] == (unsigned char)c)
			return ((void *)s + a);
		a++;
	}
	return (0);
}

// int	main(void)
// {
//    const char str[] = "http://www.w3cschool.cc";
//    const char ch = '\0';

// 	printf("%s\n", ft_memchr(str, ch, 40));
// 	printf("%s", memchr(str, ch, 40));
// }