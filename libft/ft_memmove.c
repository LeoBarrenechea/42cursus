/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:58:50 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/06 13:00:10 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	i = 0;
	while (len--)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*int main (void)
{
   unsigned char dest[] = "oldstring";
   unsigned char src[]  = "string";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 10);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   return(0);
}*/