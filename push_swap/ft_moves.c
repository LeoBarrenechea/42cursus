/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:09:36 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/29 10:56:29 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list *from, t_list *to)
{
	t_list	*aux;

	if (from->next)
	{
		if (!to)
			to = ft_addnew(from->num);
		else
		{
			aux = to;
			to->next = aux;
			to->num = from->num;
		}
		from = from->next;
	}
}

void	ft_r_rotate(t_head *list)
{
	t_list	*aux;

	if (list->peek->next)
	{
		aux = list;
		while (aux->next->next)
			aux = aux->next;
		aux->next->next = list->peek;
		list->peek = aux->next;
		aux->next = NULL;
	}
}

void	ft_rotate(t_head *list)
{
	t_list	*aux;
	t_list	*aux1;

	if (list->peek->next)
	{
		aux = list->peek;
		aux1 = list->peek->next;
		list->peek = aux;
		while (aux->next)
			aux = aux->next;
		aux->next = aux1;
		aux->next->next = NULL;
		list->lstnum = aux->next;
	}
}

void	ft_swap(t_head *peek)
{
	t_list	*aux;
	t_list	*aux1;

	if (peek->peek->next)
	{
		aux = peek->peek->next;
		aux1 = aux->next;
		aux->next = peek->peek;
		aux->next->next = aux1;
		peek->peek = aux;
	}
}
