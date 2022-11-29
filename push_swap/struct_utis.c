/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:00:31 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/29 15:32:17 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*ft_addnew(int arg)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new -> num = arg;
		new -> next = NULL;
	}
	return (new);
}

void	ft_insertend(t_head *head, int arg)
{
	t_list	*aux;
	t_list	*new;

	aux = head->peek;
	new = ft_addnew(arg);
	if (aux == NULL)
		aux = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	head->peek = aux;
	head->len++;
	head->lstnum = new;
	free (new);
	new = NULL;
}

t_head	*ft_addhead(void)
{
	t_head	*peek;

	peek = (t_head *)malloc(sizeof(t_head));
	if (!peek)
		return (0);
	peek->peek = NULL;
	peek->len = 0;
	return (peek);
}
