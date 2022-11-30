/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:40:53 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/07 17:16:19 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intcheck(int n)
{
	int	i;

	i = 0;
	if (n < 0 || !n)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	i;
	long		digit;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit = ft_intcheck(n);
	str = malloc(digit + 1);
	if (!str)
		return (0);
	str[digit] = '\0';
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i++;
	}
	while (digit-- > i)
	{
		str[digit] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
