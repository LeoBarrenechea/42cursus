/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:26:28 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/12 14:37:53 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (write (1, "(null)", 6));
	while (arg[i])
	{
		write(1, &arg[i], 1);
		i++;
	}
	return (i);
}
