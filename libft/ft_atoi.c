/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:45:43 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/10 18:43:34 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int 	i;
	int		num;
	int		sign;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] <= '9' && '0' <= str[i]) || (sign < 2))
	{
		if (str[i] == '-' || str[i] == '+')
			sign + 1;
		num = (num * 10) + str[i] - 48;
		i++;
	}
	return (num);
}

int main(void)
{
	const char* s = "-122a33";

	printf("%d\n", ft_atoi(s));
	printf("%d", atoi(s));
	return (0);
}
