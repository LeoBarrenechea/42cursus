/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_list_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:02:04 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/01 15:31:54 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error_exit(void)
{
	write (1, "Error\n", 6);
	exit (-1);
}

void	free_str_list_exit(t_head *list, char **str, int len)
{
	int		i;
	t_list	*del;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			free (str[i]);
			i++;
		}
		free (str);
	}
	if (list)
	{
		while (list->peek)
		{
			del = list->peek;
			list->peek = list->peek->next;
			free (del);
		}
		free (list);
	}
	if (len == 0)
		write_error_exit();
}
