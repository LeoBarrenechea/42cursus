/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:30:59 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/06 18:24:52 by lbarrene         ###   ########.fr       */
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
	{
		size++;
	}
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;
	size_t	src_len;
	size_t	dst_len;
	
	if (!dst || !src)
		return (0);
	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	a = dst_len;
	if (dstsize != 0)
	{
		while (src[a] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[a];
			i++;
			a++;
		}
		return (dstsize);
	}
	return (a);
}

int	main (void)
{
	char dst[] = "hola ";
	char src[] = "a todos!";

	ft_strlcat(dst, src, 4);
	printf("%s %s", dst, src);
}