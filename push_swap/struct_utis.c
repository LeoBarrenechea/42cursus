/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:00:31 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/28 13:06:42 by lbarrene         ###   ########.fr       */
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

	aux = head;
	new = ft_addnew(arg);
	if (aux == NULL)
		aux = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	head = aux;
	free (new);
	new = NULL;
}
