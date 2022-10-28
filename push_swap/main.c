/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:23:05 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/22 09:28:26 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int num;

    if (argc > 1)
    {
        i = 0;
        while (argv[++i] && !argv[i][1])
        {
            num = ft_atoi(argv[i]);
            printf("%d\n", num);
        }
        write (1, "error", 5);
    }
}