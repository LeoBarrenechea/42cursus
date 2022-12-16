/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:42:15 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/16 17:02:51 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*separa la lista a en base a un pivot*/
void	split_list_a(t_head *list_a, t_head *list_b, int num)
{
	int		pivot;

	pivot = list_a->lstnum->num;
	while (check_sort(list_a) && list_a->peek)
	{
		if (list_a->len <= 5 && check_sort(list_a))
			alg_of_5(list_a, list_b, num);
		else if (!(list_a->peek->num == pivot))
			break ;
		else if (pivot > list_a->peek->num)
			ft_push(list_a, list_b, num);
		else if (pivot < list_a->peek->num)
			ft_rotate(list_a, num);
	}
}

/*separa la lista b en base a un pivot*/
void	split_list_b(t_head *list_b, t_head *list_a, int num)
{
	int		pivot;

	pivot = list_b->lstnum->num;
	if (list_b->peek && !(list_b->peek->num == pivot))
	{
		if (pivot < list_b->peek->num)
		{
			if (list_b->peek->num < pivot)
				ft_push(list_b, list_a, num);
			else if (pivot > list_b->peek->num)
				ft_rotate(list_b, num);
		}
	}
	while (list_b->peek)
		ft_push(list_b, list_a, 1);
}

/*empieza a ordenar la lista a*/
void	alg_sort_a(t_head *list_a, t_head *list_b, int num)
{
	if (list_a->peek && check_sort(list_a))
	{
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
	if (list_b->peek)
	{
		both_moves(list_a, list_b);
		if (list_b->poshigh == 1)
			ft_push(list_b, list_a, num);
		else if (list_b->poshigh == 2)
		{
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
			&& !(list_b->poshigh == 1 && list_a->posmin == 1))
		{
			ft_rotate (list_a, 3);
			ft_rotate (list_b, 2);
		}
	}
}

void	sort_function(t_head *list_a, t_head *list_b)
{
	while (reverse_check_sort(list_b) || check_sort(list_a))
	{
		if (check_sort(list_a))
		{
			split_list_a(list_a, list_b, 0);
			alg_sort_a(list_a, list_b, 0);
		}
		else if (reverse_check_sort(list_b) && list_b->peek)
		{
			split_list_b(list_b, list_a, 1);
			alg_sort_b(list_b, list_a, 1);
		}
	}
	if (!reverse_check_sort(list_b))
		split_list_b(list_b, list_a, 1);
}
