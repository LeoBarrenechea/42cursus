/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:22:15 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/06 13:12:49 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_head *list, int num, char **str)
{
	t_list	*checker;

	if (list->peek)
	{
		checker = list->peek;
		while (checker)
		{
			if (checker->num == num)
				free_str_list_exit(list, str, 0);
			checker = checker->next;
		}
	}
}

void	check_insert(char *av, t_head *peek)
{
	int		num;
	char	**str;
	int		i;

	str = ft_split(av, ' ', peek);
	i = 0;
	while (str[i])
	{
		num = ft_atoi(str[i], peek);
		check_dup(peek, num, &str[i]);
		ft_insertend(peek, num);
		i++;
	}
	free_str_list_exit(0, str, 1);
}

int	check_sort(t_head *peek)
{
	t_list	*aux;

	aux = peek->peek;
	while (aux->next)
	{
		if (aux->num > aux->next->num)
			return (1);
		aux = aux->next;
	}
	free_str_list_exit(peek, 0, 1);
	exit (-1);
	return (0);
}
