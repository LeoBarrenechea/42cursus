/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:55:40 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/07 15:35:40 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stak	*ft_push(t_head *peek, t_stak *push)
{
	t_stak	*aux;

	if (peek->len > 1)
	{
		if (!push)
			push = ft_addnew(peek->peek->num);
		else
		{
			aux = push;
			push->num = peek->peek->num;
			push->next = aux->next;
		}
		while (push->next)
			push = push->next;
		peek->peek = peek->peek->next;
		push->next = NULL;
	}
	return (push);
}

int	main(void)
{
	t_head	*peek;
	int		i;
	t_stak	*push;

	peek = ft_addheader();
	push = NULL;
	i = 0;
	int a[] = {50,5,60,-4,3};
	while (i < 5)
	{
		ft_insertend(peek, a[i]);
		i++;
	}
	i = 0;
	while (peek->peek->next)
	{
		push = ft_push(peek, push);
		printf("[%i]  |  %d  ", i, peek->peek->num);
		printf("|  stack b |  %d\n", push->num);
		i++;
	}
}
