/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:28:27 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/08 18:12:53 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*ft_full_list(int ac, char **av)
{
	t_head	*peek;

	peek = ft_addhead();
	if (2 < ac)
	{
		while (*++av)
			check_insert(*av, peek);
	}
	else if (2 == ac && *++av)
		check_insert(*av, peek);
	if (!check_sort(peek))
	{
		free_str_list_exit(peek, 0, 1);
		exit (-1);
	}
	return (peek);
}

int	main(int ac, char **av)
{
	t_head	*list_a;
	int		i;
	t_list	*aux;
	t_head	*list_b;

	list_a = ft_full_list(ac, av);
	list_b = ft_addhead();
	i = 1;
	aux = list_a->peek->next;
	split_from_pivot(list_a, list_b, aux, 0);
/* 	while (aux)
	{
		printf("A->[%i]  |  [%d]\n", i, aux->num);
		aux = aux->next;
		i++;
	} */
	free_str_list_exit(list_a, 0, 1);
	free_str_list_exit(list_b, 0, 1);
}
