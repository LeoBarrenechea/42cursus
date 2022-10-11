/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:10:46 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/11 13:17:55 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_dec(int dec)
{
	int		num;
	char	*str;

	str = ft_itoa(dec);
	num = ft_atoi(str);
	ft_putnbr_fd(num, 1);
	return (num);
}
