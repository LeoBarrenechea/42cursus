/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:10:46 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/07 17:32:28 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(int dec)
{
	int		num;
	char	*str;

	str = ft_itoa(dec);
	num = ft_atoi(str);

	return (num);
}

int	main(void)
{
	int	str;

	str = 5444;
	print_dec(str);
	printf("\n%i", str);
	return (0);
}
