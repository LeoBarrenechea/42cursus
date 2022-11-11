/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:57:53 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/11 11:39:12 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *av)
{
	int	i;

	i = 0;
	while (*av && (av[i] < 58 && 47 < av[i]
			|| av[i] == 32 || av[i] == '-' || av[i] == '+'))
		i++;
	if (av[i] == '\0')
		return (1);
	return (0);
}

void	check_dup(t_head *peek, int num)
{
	t_stak	*check;

	check = peek->peek;
	while (check)
	{
		if (check->num == num)
		{
			write (1, "Error\n", 6);
			free_stack(peek);
			exit (-1);
		}
		check = check->next;
	}
}

void	arg_str(char **av, t_head *peek)
{
	int	num;

	av = ft_split(*av, ' ');
	while (*av)
	{
		num = ft_atoi(*av, peek);
		check_dup(peek, num);
		ft_insertend(peek, num);
		av++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_head	*peek;

	peek = ft_addheader();
	if (ac == 2)
	{
		if (av[1] && (check_num(av[1]) == 1))
			arg_str(&av[1], peek);
		else
		{
			write (1, "Error\n", 6);
			free_stack(peek);
			exit (-1);
		}
	}
	else
		free_stack(peek);
	i = 0;
	while (peek->peek)
	{
		printf("[%i]  |  [%d]\n", i, peek->peek->num);
		peek->peek = peek->peek->next;
		i++;
	}
}
