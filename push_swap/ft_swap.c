/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:31:10 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/21 17:05:15 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int len, long int *stk)
{
	int	i;
	int	swap;

	i = 0;
	if (2 <= i && len > 1)
	{
		swap = stk[i];
		stk[i] = stk[i + 1];
		stk[i + 1] = swap;
		i++;
	}
}
