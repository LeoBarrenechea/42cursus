/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:19:22 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/01 16:23:11 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*print;

	fd = open("empty.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	return (0);
}