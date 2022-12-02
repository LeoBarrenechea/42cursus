/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:23:05 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/02 15:24:43 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*ft_full_list(int ac, char **av)
{
	t_head	*peek;
	int		i;

	peek = ft_addhead();
	i = 0;
	if (2 < ac)
	{
		while (*++av)
			check_insert(*av, peek);
	}
	else if (2 == ac && *++av)
		check_insert(*av, peek);
	return (peek);
}

/* int	main(int ac, char **av)
{
	t_head	*peek;
	int		i;

	peek = ft_full_list(ac, av);
	free_str_list_exit(peek, 0, 1);
} */
