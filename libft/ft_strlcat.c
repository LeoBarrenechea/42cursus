/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:30:59 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/20 13:46:42 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *restrict src, size_t dstsize)
{
	size_t			i;
	size_t			dst_len;
	size_t			src_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = dst_len;
	if (dstsize <= dst_len || dstsize == 0)
		return (dstsize + src_len);
	while (*src && dst_len < dstsize - 1)
	{
		*(dst + dst_len) = *src++;
		dst_len++;
	}
	*(dst + dst_len) = '\0';
	return (i + src_len);
}
