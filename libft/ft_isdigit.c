/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:26:05 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/01 16:07:58 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/
#include "libft.h"

int	ft_isdigit(int arg)
{
	if (arg <= '9' && '0' <= arg)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d\n", isdigit('0'));
	printf("%d\n", ft_isdigit('0'));
}*/
