/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:54:51 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/01 16:08:01 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isascii(int arg)
{
	if (!(0 <= arg && arg <= 127))
		return (0);
	else
		return (1);
}

/*int	main(void)
{
	printf("%d\n", isascii(0));
	printf("%d\n", ft_isascii(0));
}*/
