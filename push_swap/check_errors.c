/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:22:15 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/29 23:27:50 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_head *list, char **av, int num)
{
	t_list	*checker;

	checker = list->peek;
	while (checker)
	{
		if (checker->num == num)
			free_str_list_exit(list, av, 0);
		checker = checker->next;
	}
}

int main (int ac, char **av)
{
	t_head	*peek;
	int		i;
	int		num;
	
	i = 1;
	peek = ft_addhead();
	if (ac > 1)
	{
		while (av[++i])
		{	
			num = ft_atoi(av[i]);
			check_dup(peek, av, num);
			ft_insertend(peek, num);
		}
	}
	free_str_list_exit(peek, 0, 1);
}
