/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:33:52 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/01 15:32:22 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *arg)
{
	int	size;

	size = 0;
	if (arg[size] == 0)
		return (0);
	while (arg[size])
		size++;
	return (size);
}

int	ft_atoi(char *str, t_head *ptr)
{
	int			i;
	int			sign;
	long		num;

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
	while ((str[i] <= '9' && '0' <= str[i]) || str[i] == 32)
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	if ((num * sign) <= INT_MIN || INT_MAX <= (num * sign))
		free_str_list_exit(ptr, 0, 0);
	return (num * sign);
}
