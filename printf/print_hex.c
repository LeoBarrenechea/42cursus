/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:00:13 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/11 12:33:35 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_hex(unsigned long int num, char c, int fd)
{
	int	long_n;

	long_n = 1;
	if (c == 'p' || c == 'x')
	{
		if (16 <= num)
			long_n = long_n + print_hex(num / 16, c, fd);
		ft_putchar_fd("0123456789abcdef"[num % 16], fd);
	}
	else if (c == 'X')
	{
		if (16 <= num)
			long_n = long_n + print_hex(num / 16, c, fd);
		ft_putchar_fd("0123456789ABCDEF"[num % 16], fd);
	}
	return (long_n);
}
