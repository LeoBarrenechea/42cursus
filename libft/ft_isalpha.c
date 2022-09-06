/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:48:29 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/02 12:46:32 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/
#include "libft.h"

int	ft_isalpha(int arg)
{
	if ((arg <= 90 && 65 <= arg) | (arg <= 122 && 97 <= arg))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d\n", isalpha(160));
	printf("%d\n", ft_isalpha(160));
}*/
