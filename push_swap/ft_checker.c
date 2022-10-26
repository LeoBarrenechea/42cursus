/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:01:18 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/26 17:52:12 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_param(int argc, char **argv, t_head *peek)
{
	int			i;
	int			num;

	num = 0;
	if (1 <= argc)
	{
		i = 1;
		while (argv[i] && peek != NULL)
		{
			num = ft_atoi(argv[i]);
			if (num <= INT_MIN || INT_MAX <= num)
			{
				free_stack(peek->peek);
				return ((void)0);
			}
			else
				ft_insertend(peek, num);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_stak	*list;
	t_head	*peek;

	if (argc > 1)
	{
		peek = ft_addheader();
		check_param(argc, argv, peek);
	}
	printf("%d", list->num);
}
