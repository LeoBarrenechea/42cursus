/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:55:20 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/07 12:39:41 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r_rotate(t_head *peek)
{
	t_stak	*aux;

	if (peek->len > 1)
	{
		aux = peek->peek;
		while (peek->peek->next->next)
			peek->peek = peek->peek->next;
		peek->etail = peek->peek;
		peek->peek = peek->etail->next;
		peek->etail->next = NULL;
		peek->peek->next = aux;
	}
}

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