/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:31:10 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/19 00:16:20 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_head	*peek;
	int		i;

	peek = ft_addheader();
	i = 0;
	int a[] = {50,3,2,3,4,5,6,7,8,9};
	while (i <= 9)
	{
		ft_insertend(peek, a[i]);
		i++;
	}
	i = 0;
	ft_swap(peek);
	while (peek->peek)
	{
		printf("[%i]  |  %d\n", i, peek->peek->num);
		peek->peek = peek->peek->next;
		i++;
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