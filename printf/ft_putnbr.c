/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:57:23 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/12 16:21:06 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int	n;

	n = 0;
	if (num == -2147483648)
		return (print_str("-2147483648"));
	if (0 > num)
	{
		num *= -1;
		n = ft_putchar('-');
	}
	if (10 <= num)
	{
		n += ft_putnbr(num / 10);
	}
	n += ft_putchar((num % 10) + 48);
	return (n);
}
