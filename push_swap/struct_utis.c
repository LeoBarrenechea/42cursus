/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:00:31 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/06 16:44:31 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	new = ft_addnew(arg);
	if (head->peek == NULL)
		head->peek = new;
	else
	{
		aux = head->peek;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	head->len++;
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

void	higher_num(t_head *list)
{
	t_list	*aux;
	int		hold;

	aux = list->peek;
	hold = 0;
	while (aux->next)
	{
		if (aux->num > aux->next->num)
		{	
			hold = aux->num;
			if (hold && hold < aux->num)
		}
	}
}
