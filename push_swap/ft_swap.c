/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:31:10 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/31 17:54:57 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_head *peek)
{
	t_stak	*aux;
	t_stak	*aux1;

	aux = peek->peek->next;
	aux1 = aux->next;
	if (peek->peek->next)
	{
		aux->next = peek->peek;
		aux->next->next = aux1;
		peek->peek = aux;
	}
}

int main(void)
{
	t_head	*peek;
	int		i;
	t_stak	*list;

	peek = ft_addheader();
	list = NULL;
	i = 0;
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	while (i <= 9)
	{
		ft_insertend(peek, a[i]);
		i++;
	}
	ft_swap(peek);
	while (peek->peek)
	{
		printf("%d\n", peek->peek->num);
		peek->peek = peek->peek->next;
	}
}
