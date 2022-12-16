/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:04:44 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/16 14:58:58 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_pos_moves(t_head *list, int pos, int num)
{
	if (pos == 2)
		ft_swap(list, num);
	else if (pos == 3)
	{
		ft_rotate(list, num);
		ft_swap(list, num);
	}
	else if (4 == pos || 5 == pos)
	{
		if ((pos == 4 && list->len == 5) || (pos == 4 && list->len == 4))
			ft_r_rotate(list, num);
		if (pos == 5)
			ft_r_rotate(list, num);
	}
}

void	alg_of_3(t_head *from, int num)
{
	t_list	*aux;

	aux = from->peek;
	if (!check_sort(from))
		return ;
	if (from->len == 2)
		ft_swap(from, num);
	else if (from->min->num == aux->num)
	{
		ft_swap(from, num);
		ft_rotate(from, num);
	}
	else if (from->min->num == aux->next->next->num)
	{
		if (from->high->num == aux->num)
			ft_swap(from, num);
		ft_r_rotate(from, num);
	}
	else if (from->min->num == aux->next->num)
	{
		if (from->high->num == aux->num)
			ft_rotate(from, num);
		else
			ft_swap(from, num);
	}
}

void	alg_of_5(t_head *from, t_head *to, int num)
{
	from->pushcount = 0;
	while (4 <= from->len)
	{
		first_pos_moves(from, from->posmin, num);
		ft_push(from, to, num);
		from->pushcount++;
	}
	if (from->len <= 3)
		alg_of_3(from, num);
	if (3 == from->len)
	{
		while (from->pushcount != 0)
		{
			ft_push(to, from, 1);
			from->pushcount--;
		}
	}
}
