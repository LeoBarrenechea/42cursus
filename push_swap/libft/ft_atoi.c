/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:45:43 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/11 10:29:53 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_free(void *ptr)
{
	write (1, "Error\n", 6);
	free_stack(ptr);
	exit (-1);
}

int	ft_atoi(const char *str, void *ptr)
{
	int			i;
	int			sign;
	long int	num;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] <= 13 && 9 <= str[i]) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] <= '9' && '0' <= str[i]))
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	if (num <= INT_MIN || INT_MAX <= num)
		write_free(ptr);
	return (num * sign);
}
