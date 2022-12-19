/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:42:15 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/19 14:41:39 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*separa la lista a en base a un pivot*/
int	split_list_a(t_head *list_a, t_head *list_b, int num)
{
	static int		pivot;

	pivot = list_a->lstnum->num;
	while (check_sort(list_a) && !(list_a->peek->num == pivot))
	{
		if (list_a->len <= 5 && check_sort(list_a))
			alg_of_5(list_a, list_b, num);
		else if (pivot > list_a->peek->num)
			ft_push(list_a, list_b, num);
		else if (pivot < list_a->peek->num)
			ft_rotate(list_a, num);
	}
	return (pivot);
}

/*separa la lista b en base a un pivot*/
int	split_list_b(t_head *list_b, t_head *list_a, int num)
{
	static int		pivot;

	pivot = list_b->lstnum->num;
	while (reverse_check_sort(list_b) && !(list_b->peek->num == pivot))
	{
		if (list_b->peek->num < pivot)
			ft_push(list_b, list_a, num);
		else if (pivot > list_b->peek->num)
			ft_rotate(list_b, num);
	}
	return (pivot);
}

/*empieza a ordenar la lista a*/
void	alg_sort_a(t_head *list_a, t_head *list_b, int num)
{
	while (check_sort(list_a))
	{
		if (reverse_check_sort(list_b))
			both_moves(list_a, list_b);
		if (list_a->posmin == 1)
			ft_push(list_a, list_b, num);
		else if (list_a->posmin == 2)
		{
			ft_swap(list_a, num);
			ft_push(list_a, list_b, num);
		}
		else if (list_a->posmin <= (list_a->len / 2))
			ft_rotate(list_a, num);
		else if (list_a->posmin > (list_a->len / 2))
			ft_r_rotate(list_a, num);
	}
}

/*empieza a ordenar la lista b*/
void	alg_sort_b(t_head *list_b, t_head *list_a, int num)
{
	while (list_b->peek)
	{
		if (check_sort(list_a))
			both_moves(list_a, list_b);
		if (list_b->poshigh == 1 || list_b->poshigh == 2)
		{
			if (list_b->poshigh == 2)
				ft_swap(list_b, num);
			ft_push(list_b, list_a, num);
		}
		else if (list_b->poshigh > (list_b->len / 2))
			ft_r_rotate(list_b, num);
		else if (list_b->poshigh <= (list_b->len / 2))
			ft_rotate(list_b, num);
	}
}

/*movimientos en ambas listas*/
void	both_moves(t_head *list_a, t_head *list_b)
{
	int	lena;
	int	lenb;

	lena = list_a->len / 2;
	lenb = list_b->len / 2;
	if (list_a->peek && list_b->peek)
	{
		if (list_a->posmin == 2 && list_b->poshigh == 2)
		{
			ft_swap(list_a, 3);
			ft_swap(list_b, 2);
		}
		else if (list_b->poshigh > lenb && list_a->posmin > lena)
		{
			ft_r_rotate(list_a, 3);
			ft_r_rotate(list_b, 2);
		}
		else if ((list_b->poshigh <= lenb && list_a->posmin <= lena)
			&& !(list_b->poshigh == 1 || list_a->posmin == 1))
		{
			ft_rotate (list_a, 3);
			ft_rotate (list_b, 2);
		}
	}
}

void	sort_function(t_head *list_a, t_head *list_b)
{
	int	a;

	a = split_list_a(list_a, list_b, 0);
	alg_sort_a(list_a, list_b, 0);
	alg_sort_b(list_b, list_a, 1);
}
