/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:45:43 by lbarrene          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/13 13:10:44 by lbarrene         ###   ########.fr       */
=======
/*   Updated: 2022/10/26 17:01:07 by lbarrene         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int	ft_atoi(const char *str)
=======
int	ft_atoi(const char *str, t_head *peek)
>>>>>>> refs/remotes/origin/main
{
	int	i;
	int	sign;
	int	num;

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
<<<<<<< HEAD
=======
	if (INT_MIN <= num || num <= INT_MAX)
		free_stack(peek);
>>>>>>> refs/remotes/origin/main
	return (num * sign);
}
