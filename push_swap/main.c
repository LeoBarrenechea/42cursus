/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:23:05 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/30 16:00:50 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_str(char **av, t_head *peek)
{
	int	num;

	av = ft_split(*av, ' ', peek);
	while (*av)
	{
		num = ft_atoi(*av, peek);
		av++;
	}
}

int	main(int argc, char **argv)
{
}
