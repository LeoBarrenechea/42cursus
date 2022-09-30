/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:19:22 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/30 17:30:33 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*print;

	fd = open("test1.txt", O_RDWR);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	return (0);
}