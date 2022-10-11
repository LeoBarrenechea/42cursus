/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:53:12 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/11 13:38:07 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *arg, ...)
{
	int		num;
	va_list	param;
	int		n;

	n = 0;
	while (arg[n] != '%')
	{
		if (arg[n + 1] == '%' && arg[n] == '%')
			write(1, '%', 1);
		write (1, arg[n], 1);
		n++;
	}
	if (arg == 's' || arg == 'c')
		num += print_char_str(va_arg (param, char *));
	if (arg == 'i' || arg == 'd')
		num += print_dec(va_arg (param, long int));
	if (arg == 'p' || arg == 'x' || arg == 'X')
		num += print_hex(va_arg (param, int), arg, 1);
	if (arg == 'u')
		num += print_unsigned(va_arg (param, unsigned int));
	return (num);
}
