/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:42:15 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/08 18:16:03 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_from_pivot(t_head *pivot, t_head *to, t_list *peek, int num)
{

	while (pivot)
	{
		if (pivot->peek->num < peek->num)
		{
			ft_swap(pivot, num);
			ft_push(pivot, to, num);
		}
		if (pivot->peek->num < pivot->lstnum->num)
		{
			ft_r_rotate(pivot, num);
			ft_push(pivot, to, num);
		}
		else
		{
			ft_swap(pivot, num);
			ft_rotate(pivot, num);
		}
	}
}

/* void	move_pivot(t_head *list_a)
{
	if (list_a->posmin < (list_a->len / 2))
	{
		while (list_a->posmin != 1)
		{
			
		}
	}
}

void	alg_sort(t_head *list_a, t_head *list_b)
{
} */
