/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:42:15 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/09 14:26:25 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_from_pivota(t_head *list_a, t_head *list_b, int num)
{
	t_list	*aux;
	int		pivot;

	aux = list_a->peek;
	pivot = list_a->lstnum->num;
	while (list_a->peek && num == 0)
	{
		if (pivot > list_a->peek->num)
			ft_push(list_a, list_b, num);
		else if (pivot < list_a->peek->num)
			ft_rotate(list_a, num);
		else if (list_a->peek->num == pivot)
			break ;
	}
	return (pivot);
}

int	split_from_pivotb(t_head *list_b, t_head *list_a, int num)
{
	t_list	*aux;
	int		pivot;

	aux = list_b->peek;
	pivot = list_b->lstnum->num;
	while (list_b->peek && num == 1)
	{
		if (pivot < list_b->peek->num)
			ft_push(list_b, list_a, num);
		else if (pivot > list_b->peek->num)
			ft_rotate(list_b, num);
		else if (list_b->peek->num == pivot)
			break ;
	}
	return (pivot);
}

int	sort_list(t_head *from, t_head *to, int num)
{
	int	pivot;

	pivot = 0;
	if (from->len > 1 && num == 0)
	{
		while (from->len > 5)
			pivot = split_from_pivota(from, to, num);
		if (from->len <= 5)
			alg_of_5(from, to, num);
	}
	if (from->len > 1 && num == 1)
		while (from->len > 5)
			pivot = split_from_pivotb(from, to, num);
	return (pivot);
}

/* void	alg_sort(t_head *list_a, t_head *list_b)
{
} */
