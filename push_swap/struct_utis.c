/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:00:31 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/04 13:09:46 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stak	*ft_addnew(int arg)
{
	t_stak	*new;

	new = (t_stak *)malloc(sizeof(t_stak));
	if (new != NULL)
	{
		new -> num = arg;
		new -> next = NULL;
	}
	return (new);
}

 /* have to create stack a nd stack b*/
t_head	*ft_addheader(void)
{
	t_head	*peek;

	peek = (t_head *)malloc(sizeof(t_head));
	peek->len = 0;
	peek->peek = NULL;
	return (peek);
}

void	ft_insertinit(t_head *peek, int arg)
{
	t_stak	*new;

	new = ft_addnew(arg);
	peek->peek = new;
	peek->len++;
}

void	ft_insertend(t_head *peek, int arg)
{
	t_stak	*aux;
	t_stak	*new;

	new = ft_addnew(arg);
	if (peek->peek == NULL)
		peek->peek = new;
	else
	{
		aux = peek->peek;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	peek->etail = new;
	peek->len++;
}

void	free_stack(t_head *list)
{
	free(list);
}
