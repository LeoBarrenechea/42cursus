/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:19:22 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/01 23:42:42 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


int	main(void)
{
	int		fd;
	char	*print;

	fd = open("empty.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	fd = open("multiple_nl.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	fd = open("test1.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	fd = open("test.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	fd = open("only_nl.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	fd = open("one_line_no_nl.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	fd = open("lines_around_10.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	fd = open("variable_nls.txt", O_RDONLY);
	print = get_next_line(fd);
	printf("|%s", print);
	free(print);
	/* print = get_next_line_bonus(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line_bonus(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line_bonus(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line_bonus(fd);
	printf("|%s", print);
	free(print);
	print = get_next_line_bonus(fd);
	printf("|%s", print);
	free(print); */
	return (0);
}