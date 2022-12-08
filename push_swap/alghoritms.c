/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:04:44 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/08 16:10:32 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_pos_moves(t_head *list, int pos)
{
	if (pos == 2)
		ft_swap(list, 0);
	else if (pos == 3)
	{
		ft_rotate(list, 0);
		ft_swap(list, 0);
	}
	else if (4 == pos || 5 == pos)
	{
		if ((pos == 4 && list->len == 5) || (pos == 4 && list->len == 4))
			ft_r_rotate(list, 0);
		if (pos == 5)
			ft_r_rotate(list, 0);
	}
}

void	alg_of_3(t_head *list_a)
{
	t_list	*aux;

	aux = list_a->peek;
	if (!check_sort(list_a))
		return ;
	if (list_a->len == 2)
		ft_swap(list_a, 0);
	else if (list_a->min->num == aux->num)
	{
		ft_swap(list_a, 0);
		ft_rotate(list_a, 0);
	}
	else if (list_a->min->num == aux->next->next->num)
	{
		if (list_a->high->num == aux->num)
			ft_swap(list_a, 0);
		ft_r_rotate(list_a, 0);
	}
	else if (list_a->min->num == aux->next->num)
	{
		if (list_a->high->num == aux->num)
			ft_rotate(list_a, 0);
		else
			ft_swap(list_a, 0);
	}
}

void	alg_of_5(t_head *list_a, t_head *list_b)
{
	while (4 <= list_a->len)
	{
		if (list_a->posmin != 1)
			first_pos_moves(list_a, list_a->posmin);
		ft_push(list_a, list_b, 1);
	}
	if (list_a->len <= 3)
		alg_of_3(list_a);
	if (list_b->len <= 2)
	{
		if (list_b->len == 2)
			ft_push(list_b, list_a, 0);
		if (list_b->len == 1)
			ft_push(list_b, list_a, 0);
	}
}
