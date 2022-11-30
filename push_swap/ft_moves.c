/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:09:36 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/30 16:00:41 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_head *from, t_head *to, int num)
{
	t_list	*aux;

	if (!from)
		return (0);
	aux = from->peek->next;
	from->peek->next = to->peek;
	to->peek = from->peek;
	from->peek = aux;
	from->len--;
	to->len++;
	if (num == 1)
		write (1, "pb\n", 3);
	else if (num == 0)
		write (1, "pa\n", 3);
}

void	ft_r_rotate(t_head *list, int num)
{
	t_list	*holder;
	t_list	*aux;

	if (list->peek->next)
	{
		aux = list;
		while (aux->next->next)
			aux = aux->next;
		aux->next->next = list->peek;
		list->peek = aux->next;
		aux->next = NULL;
		if (num == 0)
			write (1, "rra\n", 4);
		else if (num == 1)
			write (1, "rrb\n", 4);
		else if (num == 2)
			write (1, "rrr\n", 4);
	}
}

void	ft_rotate(t_head *list, int num)
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
		if (num == 0)
			write (1, "ra\n", 3);
		else if (num == 1)
			write (1, "rb\n", 3);
		else if (num == 2)
			write (1, "rr\n", 3);
	}
}

void	ft_swap(t_head *peek, int num)
{
	t_list	*aux;
	t_list	*aux1;

	{
		aux = peek->peek->next;
		aux1 = aux->next;
		aux->next = peek->peek;
		aux->next->next = aux1;
	}
	if (num == 0)
		write (1, "sa\n", 3);
	else if (num == 1)
		write (1, "sb\n", 3);
	else if (num == 2)
		write (1, "ss\n", 3);
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

/* int main(void)
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
} */
