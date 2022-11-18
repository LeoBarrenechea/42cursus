/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:31:10 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/28 10:54:25 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_head *peek, t_stak *list, int arg)
{
	t_stak	*new;

	new = ft_addnew(arg);
	if (list > 1)
	{
		new = peek->peek;
		peek->peek = list->next;
		list->next = new;
	}
}

int main (void)
{
	int num[] = {1,2,3,4,5,6,7,8};
	t_head	*peek;
	t_stak	*list;
	
	ft_swap(peek, list, *num);
	printf("%d", peek->peek);
	printf("%d", list->next);
}