/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:22:20 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/23 23:47:07 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stak  *ft_save_param(t_stak *list, int *arg)
{   
    t_stak  *new;
    
    new = (t_stak *)malloc(sizeof(t_stak));
    new -> num = arg;
    new -> next = NULL;
    if (list == NULL)
        list = new;
    return (new);
}

int  ft_param_size(t_stak *num)
{   
    int size;

    size = 0;
    while (num)
    {
        num = num -> next;
        size++;
    }
    return (size);
}

t_stak  *ft_check_param(int *arg, int size)
{
    t_stak  *num;
    int     i;
    
    i = 0;
    if (!arg && !size)
        return (NULL);
    while (arg[i])
    {
        num = ft_save_param(num, arg);
        i++;
    }
    size = ft_param_size(num);
    return (num);
}

int main(void)
{
    int arg[4] = {1, 2, 3, 4};
    t_stak  *list;
    
    list = ft_save_param(list, arg);
    printf("%d\n", list);
    printf("%d\n", list);
    printf("%d\n", list);
    printf("%d\n", list);   
}