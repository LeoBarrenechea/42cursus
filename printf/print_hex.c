/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:00:13 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/12 16:30:50 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long int num, char c)
{
	int	long_n;

	long_n = 0;
	if (c == 'p' || c == 'x')
	{
		if (16 <= num)
			long_n += print_hex(num / 16, c);
		long_n += ft_putchar("0123456789abcdef"[num % 16]);
	}
	else if (c == 'X')
	{
		if (16 <= num)
			long_n += print_hex(num / 16, c);
		long_n += ft_putchar("0123456789ABCDEF"[num % 16]);
	}
	return (long_n);
}
