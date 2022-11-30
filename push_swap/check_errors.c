/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:22:15 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/30 15:54:09 by lbarrene         ###   ########.fr       */
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
