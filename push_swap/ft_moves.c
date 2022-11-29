/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:09:36 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/28 11:37:10 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_push(t_list *from, t_list *to)
{
	t_list	*aux;

	if (from->next)
	{
		if (!to)
			to = ft_addnew(from->num);
		else
		{
			aux = to;
			to = from;
			to->next = aux;
		}
		from = from->next;
	}
	return (to);
}

void	ft_r_rotate(t_list *list)
{
	t_list	*holder;
	t_list	*aux;
	if (list->next)
	{
		holder = list;
		aux = list->next;
		while (holder->next)
			holder = holder->next;
		holder->next = list;
		holder->next->next = NULL;
		list = aux;
	}
}

/* void	ft_rotate(t_listpeek
{
	t_list	*aux;
	t_list	*aux1;

	ifpeepeek>next)
	{
		aux peepeek>next;
		aux1 peepeek
peepeek= aux;
		while (aux->next)
			aux = aux->next;
		aux->next = aux1;
		aux->next->next = NULL;
peek>etail = aux->next;
	}
} */

/* void	ft_swap(t_headpeek
{
	t_stak	*aux;
	t_stak	*aux1;

	ifpeepeek>next)
	{
		aux peepeek>next;
		aux1 = aux->next;
		aux->next peepeek
		aux->next->next = aux1;
peepeek= aux;
	}
} */

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

t_list	*ft_insertend(t_list **head, int arg)
{
	t_list	*new;
	t_list	*aux;

	new = ft_addnew(arg);
	if (*head == NULL)
		*head = new;
	else
	{
		aux = *head;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	*head = aux;
	free(new);
	new = NULL;
	return (head);
}

int main(void)
{
	t_list	**peek;
	int		i;

	i = 0;
	int a[] = {50, 40, 29, 18};
	while (i <= 3)
	{
		*peek = ft_insertend(peek, a[i]);
		i++;
	}
	i = 0;
	ft_r_rotate(*peek);
	while ((*peek)->next)
	{
		printf("[%i]  |  %d\n", i, (*peek)->num);
		(*peek) = (*peek)->next;
		i++;
	}
}