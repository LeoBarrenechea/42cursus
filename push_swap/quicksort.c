/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:42:15 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/13 16:50:58 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*separa la lista a en base a un pivot*/
void	split_list_a(t_head *list_a, t_head *list_b, int num)
{
	int		pivot;

	pivot = list_a->lstnum->num;
	while (list_a->peek && !(list_a->peek->num == pivot))
	{
		if (pivot > list_a->peek->num)
			ft_push(list_a, list_b, num);
		else if (pivot < list_a->peek->num)
			ft_rotate(list_a, num);
	}
}

/*separa la lista b en base a un pivot*/
void	split_list_b(t_head *list_b, t_head *list_a, int num)
{
	int		pivot;

	pivot = list_b->lstnum->num;
	while (list_b->peek && !(list_b->peek->num == pivot))
	{
		if (pivot < list_b->peek->num)
			ft_push(list_b, list_a, num);
		else if (pivot > list_b->peek->num)
			ft_rotate(list_b, num);
	}
	if (!reverse_check_sort(list_b))
	{
		while (list_b->peek)
			ft_push(list_b, list_a, num);
	}
}

void	alg_sort_a(t_head *list_a, t_head *list_b, int num)
{
	while (check_sort(list_a) == 1)
	{
		if (list_a->peek->num > list_a->lstnum->num)
			ft_rotate(list_a, num);
		else if (list_a->peek->num < list_a->peek->next->num)
		{
			ft_push(list_a, list_b, num);
		}
		else
		{
			ft_swap(list_a, num);
			ft_push(list_a, list_b, num);
		}
	}
}

void	alg_sort_b(t_head *list_b, t_head *list_a, int num)
{
	while (list_b->peek && reverse_check_sort(list_a) == 1)
	{
		if (list_b->peek->num == list_b->high->num)
			ft_push(list_b, list_a, num);
		else if (list_b->lstnum->num == list_b->high->num)
		{
			ft_r_rotate(list_b, num);
			ft_push(list_b, list_a, num);
		}
		else
			ft_rotate(list_b, num);
	}
}
