/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:28:27 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/06 15:01:45 by lbarrene         ###   ########.fr       */
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
	check_sort(peek);
	return (peek);
}

int	main(int ac, char **av)
{
	t_head	*peek;
	int		i;
	t_list	*aux;

	peek = ft_full_list(ac, av);
	aux = peek->peek;
	i = 0;
	alg_of_3(peek);
/* 	while (peek->peek)
	{
		printf("[%i]  |  [%d]\n", i, peek->peek->num);
		peek->peek = peek->peek->next;
		i++;
	} */
	free_str_list_exit(peek, 0, 1);
}
