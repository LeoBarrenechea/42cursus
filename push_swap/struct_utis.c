/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:00:31 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/08 17:24:47 by lbarrene         ###   ########.fr       */
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
	higher_min_num(head);
	head->lstnum = new;
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

void	higher_min_num(t_head *list)
{
	t_list	*aux;

	aux = list->peek;
	list->high = aux;
	list->min = aux;
	while (aux)
	{
		if (aux->num > list->high->num)
			list->high = aux;
		else if (aux->num < list->min->num)
			list->min = aux;
		aux = aux->next;
	}
}

void	ptr_lst_num(t_head *list)
{
	t_list	*aux;

	aux = list->peek;
	while (aux)
		aux = aux->next;
	list->lstnum = aux;
}
