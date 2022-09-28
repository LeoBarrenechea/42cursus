/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:19:22 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/28 14:07:21 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
{
    int fd;

	fd = open("test.txt", O_RDONLY);
	if (fd > 0)
	{
        printf("%s", get_next_line(fd));
	}
    return (0);
}