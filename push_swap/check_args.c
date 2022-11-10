/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:57:53 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/10 16:22:15 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	num;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] <= 13 && 9 <= str[i]) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] <= '9' && '0' <= str[i]))
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	if (num <= INT_MIN || INT_MAX <= num)
	{
		write (1, "Error\n", 6);
		exit (-1);
	}
	return (num * sign);
}

int	check_num(char *av)
{
	int	i;

	i = 0;
	while (*av && (av[i] < 58 && 47 < av[i] || av[i] == 32 || av[i] == '-'))
		i++;
	if (av[i] == '\0')
		return (1);
	return (0);
}

void	arg_str(char **av, t_head *peek)
{
	int	num;

	av = ft_split(*av, ' ');
	while (*av)
	{
		num = ft_atoi(*av);
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
		}
	}
	i = 0;
	while (peek->peek)
	{
		printf("[%i]  |  [%d]\n", i, peek->peek->num);
		peek->peek = peek->peek->next;
		i++;
	}
}
