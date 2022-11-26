/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:13:22 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/19 00:15:59 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*librerys*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include "./libft/libft.h"

/*struct*/
typedef struct s_stak
{
	int				num;
	struct s_stak	*next;
}	t_stak;

typedef struct s_head
{
	t_stak			*peek;
	t_stak			*etail;
	int				len;
	int				smaller;
	int				larger;
}	t_head;

/*push_swap functions*/
void	ft_swap(t_head *peek);
t_stak	*ft_push(t_head *peek, t_stak *b);
void	ft_r_rotate(t_head *peek);
void	ft_rotate(t_head *peek);

/*struct functions*/
t_stak	*ft_addnew(int arg);
t_head	*ft_addheader(void);
void	free_stack(t_head *peek, int i);
void	ft_insertend(t_head *peek, int arg);
void	ft_insertinit(t_head *peek, int arg);

#endif