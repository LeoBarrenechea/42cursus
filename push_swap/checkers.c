/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:10:10 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/16 16:41:03 by lbarrene         ###   ########.fr       */
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
	check_position(peek, peek->min, peek->high);
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
	return (0);
}

int	reverse_check_sort(t_head *peek)
{
	t_list	*aux;

	if (peek->peek)
	{
		aux = peek->peek;
		while (aux->next)
		{
			if (aux->num < aux->next->num)
				return (1);
			aux = aux->next;
		}
	}
	return (0);
}

void	check_position(t_head *list, t_list *min, t_list *high)
{
	t_list	*aux;
	int		pos;

	if (list->peek)
	{
		aux = list->peek;
		pos = 1;
		while (aux)
		{
			if (aux->num == min->num)
				list->posmin = pos;
			else if (aux->num == high->num)
				list->poshigh = pos;
			aux = aux->next;
			pos++;
		}
	}
	else
	{
		list->posmin = 0;
		list->poshigh = 0;
	}
}
