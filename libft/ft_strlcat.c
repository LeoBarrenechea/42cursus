/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:30:59 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/07 20:33:37 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (!dst || !src)
		return (0);
	while (dst[i] != '\0')
		i++;
	while (src[a] != '\0' && i < dstsize)
	{
		dst[i] = src[a];
		i++;
		a++;
	}
	return (i);
}

// int	main (void)
// {
// 	char dst[] = "hola como estais";
// 	char src[] = "todos bien?";
// 	unsigned int	n = 13;

// 	ft_strlcat(dst, src, n);
// 	printf("%s", "%s", dst, src);
// }