/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:36:09 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/07 20:59:04 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <ctype.h>

int	ft_toupper(int c)
{
	if (c <= 122 && 97 <= c)
		c -= 32;
	return (c);
}

/*int	main(void)
{
	printf("%c", ft_toupper(122));
}*/