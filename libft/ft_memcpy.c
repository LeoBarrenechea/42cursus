/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:01:19 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/06 13:03:54 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if ((dst == src) || n == 0)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[a];
		i++;
		a++;
	}
	n = '\0';
	return (dst);
}

/*int	main(void)
{
	unsigned char		src[] = "\0";
	unsigned char	*dst = NULL;

	//printf("before mmcpy dst = %s\n", dst);
	//memcpy(dst, src, 4);
	//printf("After memcpy dst = %s\n", dst);
	printf("before mmcpy dst = %s\n", dst);
	ft_memcpy(dst, src, 1);
	printf("after memcpy dst = %s\n", dst);
}*/