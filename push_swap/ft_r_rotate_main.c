/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_rotate_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:55:20 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/09 12:11:33 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_head	*peek;
	int		i;

	peek = ft_addheader();
	i = 0;
	int a[] = {50};
	while (i < 1)
	{
		ft_insertend(peek, a[i]);
		i++;
	}
	i = 0;
	ft_r_rotate(peek);
	while (peek->peek)
	{
		printf("[%i]  |  %d\n", i, peek->peek->num);
		peek->peek = peek->peek->next;
		i++;
	}
}