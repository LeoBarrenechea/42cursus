/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:04:34 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/28 13:57:30 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_list(t_head *list)
{
    t_list  *aux;
    
    if (list)
    {
        while (list->peek)
        {
            aux = list->peek;
            list->peek = list->peek->next;
            free (aux);
            aux = NULL;
        }
        free (list);
        list = NULL;
    }
}

void    free_list_error(t_head *list, char **str, int param)
{
    int i;

    i = 0;
    if (list)
        free_list(list);
    while (str[i])
    {
        free (str[i]);
        str[i] = NULL;
        i++;
    }
    free (str);
    str = NULL;
    if (param == 0)
    {
        write (1, "Error\n", 6);
        exit (-1);
    }
}