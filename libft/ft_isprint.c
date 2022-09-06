/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:14:52 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/01 16:07:54 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/
#include "libft.h"

int	ft_isprint(int arg)
{
	if (32 <= arg && arg <= 126)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_isprint(126));
	printf("%d\n", isprint(126));
}*/
