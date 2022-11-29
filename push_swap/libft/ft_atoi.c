/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:45:43 by lbarrene          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/19 00:16:58 by lbarrene         ###   ########.fr       */
=======
/*   Updated: 2022/11/18 13:52:17 by lbarrene         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int	ft_atoi(const char *str, t_head *peek)
=======
void	write_free(void *ptr)
{
	write (1, "Error\n", 6);
	while (ptr)
		free_stack(ptr, 1);
	exit (-1);
}

int	ft_atoi(const char *str, t_head *ptr)
>>>>>>> refs/remotes/origin/main
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
	if (INT_MIN <= num || num <= INT_MAX)
		free_stack(peek);
	return (num * sign);
}
