/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:18:05 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/11 14:44:49 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_less(t_head *a)
{
	t_stak	*aux;
	t_stak	*hold;

	aux = a->peek;
	while (aux->next)
	{
		if (aux->num > aux->next->num)
		{
			hold = aux->num;
		}
		else if (hold->num < aux->num)
			a->larger = aux->num;
		aux = aux->next;
	}
	a->smaller = aux->num;
}

void	three_args(t_head *a, t_head *b)
{
	if (check_sort(a) == 0)
	{
		
	}
}
