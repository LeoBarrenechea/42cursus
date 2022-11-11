/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:09:36 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/11 17:04:37 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stak	*ft_push(t_head *peek, t_stak *b)
{
	t_stak	*aux;

	if (peek->len > 1)
	{
		if (!b)
			b = ft_addnew(peek->peek->num);
		else
		{
			aux = b;
			b->num = peek->peek->num;
			b->next = aux->next;
		}
		while (b->next)
			b = b->next;
		peek->peek = peek->peek->next;
		b->next = NULL;
		free_stack(aux);
	}
	free_stack(peek);
	return (b);
}

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
		free_stack(aux);
	}
}

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
		free_stack(aux);
		free_stack(aux1);
	}
}

void	ft_swap(t_head *peek)
{
	t_stak	*aux;
	t_stak	*aux1;

	if (peek->peek->next)
	{
		aux = peek->peek->next;
		aux1 = aux->next;
		aux->next = peek->peek;
		aux->next->next = aux1;
		peek->peek = aux;
		free_stack(aux);
		free_stack(aux1);
	}
}
