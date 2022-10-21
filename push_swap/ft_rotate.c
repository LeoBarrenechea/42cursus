/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:12:16 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/21 17:34:56 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_rotate(int len, int *stk)
{
	int	i;
	int	count;
	int	swap;

	i = 0;
	while (stk[i])
		i++;
	count = i;
	i = 0;
	while (stk[i])
	{
		if (i == 0)
		{
			swap = stk[count - 1];
			stk[count] = stk[i];
			stk[i] = swap;
		}
		else if (i < count && len > 1)
		{
			ft_swap(count, stk);
		}
		i++;
	}

}
