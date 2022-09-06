/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:34:47 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/01 16:08:07 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/
#include "libft.h"

int	ft_isalnum(int arg)
{
	if ((48 <= arg && arg <= 57)
		| (65 <= arg && arg <= 90)
		| (97 <= arg && arg <= 122))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d\n", isalnum(123));
	printf("%d\n", ft_isalnum(123));
}*/
