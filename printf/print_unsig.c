/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:42:52 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/11 12:58:56 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	putnbr_fd(int n, int fd)
{
	unsigned int	num;
	int				long_n;

	long_n = 1;
	num = n;
	if (10 <= num)
	{
		ft_putnbr_fd((num / 10), fd);
	}
	ft_putchar_fd((num % 10 + 48), fd);
	return (long_n);
}

int	print_unsig(unsigned int num)
{
	char	*str;

	str = ft_itoa(num);
	num = ft_atoi(str);
	putnbr_fd(num, 1);
	return (num);
}
