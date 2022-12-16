/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:09:36 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/16 14:12:35 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_head *from, t_head *to, int num)
{
	t_list	*aux;

	if (!from)
		return ((void)0);
	aux = from->peek->next;
	from->peek->next = to->peek;
	to->peek = from->peek;
	from->peek = aux;
	from->len--;
	to->len++;
	if (num == 0)
		write (1, "pb\n", 3);
	else if (num == 1)
		write (1, "pa\n", 3);
	higher_min_num(from);
	higher_min_num(to);
	ptr_lst_num(from);
	ptr_lst_num(to);
	check_position(from, from->min, from->high);
	check_position(to, to->min, to->high);
}

void	ft_r_rotate(t_head *list, int num)
{
	t_list	*aux;

	if (list->peek->next)
	{
		aux = list->peek;
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
	ptr_lst_num(list);
	check_position(list, list->min, list->high);
}

void	ft_rotate(t_head *list, int num)
{
	t_list	*aux;

	if (list->peek->next)
	{
		aux = list->peek;
		while (list->peek->next)
			list->peek = list->peek->next;
		list->peek->next = aux;
		list->peek = aux->next;
		aux->next = NULL;
		if (num == 0)
			write (1, "ra\n", 3);
		else if (num == 1)
			write (1, "rb\n", 3);
		else if (num == 2)
			write (1, "rr\n", 3);
	}
	ptr_lst_num(list);
	check_position(list, list->min, list->high);
}

void	ft_swap(t_head *peek, int num)
{
	t_list	*aux;

	aux = peek->peek;
	if (aux->next)
	{
		peek->peek = aux->next;
		aux->next = aux->next->next;
		peek->peek->next = aux;
	}
	if (num == 0)
		write (1, "sa\n", 3);
	else if (num == 1)
		write (1, "sb\n", 3);
	else if (num == 2)
		write (1, "ss\n", 3);
	ptr_lst_num(peek);
	check_position(peek, peek->min, peek->high);
}

/* int	main(int ac, char **av)
{
	t_head	*list_a;
	t_list	*list;

	list_a = ft_full_list(ac, av);
	printf("***list A***\n\n");
	list = list_a->peek;
	while (list)
	{
		printf("[%i]  |  [%d]\n", list_a->len, list->num);
		list = list->next;
	}
	printf("\n***list A rotate***\n\n");
	ft_swap(list_a, 3);
	while (list_a->peek)
	{
		printf("[%i]  |  [%d]\n", list_a->len, list_a->peek->num);
		list_a->peek = list_a->peek->next;
	}
	free_str_list_exit(list_a, 0, 1);
} */
