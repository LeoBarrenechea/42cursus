/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:12:16 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/09 12:11:39 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_head	*peek;
	int		i;
	t_stak	*aux;

	peek = ft_addheader();
	i = 0;
	int a[] = {50,4,5,8,9,3};
	aux = peek->peek;
	while (i <= 5)
	{
		ft_insertend(peek, a[i]);
		i++;
	}
	i = 0;
	while (aux->next)
	{
		printf("[%i]  |  %d\n", i, aux->num);
		aux = aux->next;
		i++;
	}
	ft_rotate(peek);
	i = 0;
	while (peek->peek)
	{
		printf("[%i]  |  %d\n", i, peek->peek->num);
		peek->peek = peek->peek->next;
		i++;
	}
}
