/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:50:16 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/12 16:18:18 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsig(unsigned int num)
{
	unsigned int	long_n;

	long_n = 0;
	if (10 <= num)
	{
		long_n += ft_putnbr_unsig(num / 10);
	}
	long_n += ft_putchar((num % 10) + 48);
	return (long_n);
}
