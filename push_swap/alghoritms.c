/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:04:44 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/07 18:28:37 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		check_position(list_a, list_a->min);
		if (list_a->pos != 1)
			first_pos_moves(list_a, list_a->pos);
		ft_push(list_a, list_b, 1);
	}
	if (list_a->len <= 3)
	{
		alg_of_3(list_a);
		if(list_b)
		{
			ft_push(list_b, list_a, 0);
			ft_push(list_b, list_a, 0);
		}
	}
}
