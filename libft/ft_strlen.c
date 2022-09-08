/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:29:00 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/07 18:47:21 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  #include <stdio.h>
//  #include <string.h>
#include "libft.h"

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

// int	main(void)
// {
// 	char	arg[] = "\0";
// 	printf("%lu\n", ft_strlen(arg));
// 	printf("%lu\n", strlen(arg));
// }
