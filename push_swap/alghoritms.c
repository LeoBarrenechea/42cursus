/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:04:44 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/06 16:31:21 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_of_3(t_head *list_a)
{
	t_list	*aux;

	aux = list_a->peek;
	if (list_a->len == 2)
		ft_swap(list_a, 0);
	else if ((aux->num < aux->next->num) && (aux->num > aux->next->next->num))
	{
		if (aux->next->num < aux->next->next->num)
			ft_swap(list_a, 0);
		else
			ft_r_rotate(list_a, 0);
	}
	else if (aux->next->num > aux->next->next->num)
	{
		ft_swap(list_a, 0);
		ft_rotate(list_a, 0);
	}
	else if (aux->num < aux->next->next->num)
		ft_swap(list_a, 0);
}

void alg_of_5(t_head *list_a, t_head *list_b)
{
	t_list	*aux;

	aux = list_a->peek;
	if (list_a->len > 3)
	{
		while (4 > list_a->len)
			ft_push(list_a, list_b, 0);
		if (list_a->len == 3)
			alg_of_3(list_a);
		while (0 <= list_b->len)
			ft_push(list_b, list_a, 1);
		
	}
}
