/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:12:16 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/04 17:38:18 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertend(t_head *peek, int arg)
{
	t_stak	*aux;
	t_stak	*new;

	new = ft_addnew(arg);
	if (peek->peek == NULL)
		peek->peek = new;
	else
	{
		aux = peek->peek;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	peek->etail = new;
	peek->len++;
}

t_stak	*ft_addnew(int arg)
{
	t_stak	*new;

	new = (t_stak *)malloc(sizeof(t_stak));
	if (new != NULL)
	{
		new -> num = arg;
		new -> next = NULL;
	}
	return (new);
}

 /* have to create stack a nd stack b*/
t_head	*ft_addheader(void)
{
	t_head	*peek;

	peek = (t_head *)malloc(sizeof(t_head));
	peek->len = 0;
	peek->peek = NULL;
	return (peek);
}

void	ft_rotate(t_head *peek)
{
	t_stak	*aux;
	t_stak	*aux1;

	if (peek->peek->next)
	{
		aux = peek->peek->next;
		aux1 = peek->peek;
		peek->peek = aux;
		while (aux->next)
			aux = aux->next;
		aux->next = aux1;
		aux->next->next = NULL;
		peek->etail = aux->next;
	}
}

int main(void)
{
	t_head	*peek;
	int		i;
	t_stak	*aux;
	
	peek = ft_addheader();
	i = 0;
	int a[] = {50,4,5,8,9,3};
	aux = peek->peek;
	while (i <= 5)
	{
		ft_insertend(peek, a[i]);
		i++;
	}
	i = 0;
	while (aux->next)
	{
		printf("[%i]  |  %d\n", i, aux->num);
		aux = aux->next;
		i++;
	}
	ft_rotate(peek);
	i = 0;
	while (peek->peek)
	{
		printf("[%i]  |  %d\n", i, peek->peek->num);
		peek->peek = peek->peek->next;
		i++;
	}
}
