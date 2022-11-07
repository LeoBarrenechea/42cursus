/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:12:16 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/04 17:44:40 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_head *peek)
{
	t_stak	*aux;
	t_stak	*aux1;

	if (peek->peek->next)
	{
		aux = peek->peek->next;
		aux1 = peek->peek;
		peek->peek = aux;
		while (aux->next)
			aux = aux->next;
		aux->next = aux1;
		aux->next->next = NULL;
		peek->etail = aux->next;
	}
}

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
