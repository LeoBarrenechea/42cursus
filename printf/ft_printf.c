/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:53:12 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/30 15:58:57 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parameter(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += print_str(va_arg(arg, char *));
	else if (c == 'i' || c == 'd')
		len += (ft_putnbr(va_arg(arg, int)));
	else if (c == 'p')
		len += print_str("0x") + print_hex(va_arg(arg, unsigned long int), c);
	else if (c == 'x' || c == 'X')
		len += print_hex(va_arg(arg, unsigned int), c);
	else if (c == 'u')
		len += ft_putnbr_unsig(va_arg(arg, unsigned int));
	else
	{
		if (c == '%')
		len += ft_putchar('%');
	}
	return (len);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	va_list	arg;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, s);
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			count++;
			i++;
		}
		else if (s[i] == '%')
		{
			count += ft_parameter(arg, s[i + 1]);
			i += 2;
		}
	}
	va_end(arg);
	return (count);
}
