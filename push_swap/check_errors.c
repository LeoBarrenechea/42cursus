/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:22:15 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/29 15:48:19 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		num;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] <= 13 && 9 <= str[i]) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] <= '9' && '0' <= str[i]) || str[i] == 32)
	{
		if (!(str[i] == 32))
			num = (num * 10) + str[i] - 48;
		i++;
	}
	return (num * sign);
}

t_list	*ft_addnew(int arg)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new -> num = arg;
		new -> next = NULL;
	}
	return (new);
}

t_head	*ft_addhead(void)
{
	t_head	*peek;

	peek = (t_head *)malloc(sizeof(t_head));
	if (!peek)
		return (0);
	peek->peek = NULL;
	peek->len = 0;
	return (peek);
}


void	ft_insertend(t_head *head, int arg)
{
	t_list	*aux;
	t_list	*new;

	aux = head->peek;
	new = ft_addnew(arg);
	if (aux == NULL)
		aux = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	head->peek = aux;
	head->len++;
	head->lstnum = new;
	free (new);
	new = NULL;
}

void	write_error_exit(void)
{
	write (1, "Error\n", 1);
	exit (-1);
}

void	free_str_list_exit(t_head *list, char **str, int len)
{
	int		i;
	t_list	*del;

	if (str && len == 1)
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

void	check_dup(t_head *peek, char **av, int num)
{
	t_list	*checker;

	checker = peek->peek;
	while (checker)
	{
		if (checker->num == num)
			free_str_list_exit(peek, av, 0);
		checker = checker->next;
	}
}

int main (int ac, char **av)
{
	t_head	*peek;
	int		i;
	int		num;

	i = 0;
	peek = ft_addhead();
	while (*av)
	{	
		num = ft_atoi(av[++i]);
		check_dup(peek, av, num);
		ft_insertend(peek, num);
	}
}
