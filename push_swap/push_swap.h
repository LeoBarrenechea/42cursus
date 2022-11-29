/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:13:22 by lbarrene          #+#    #+#             */
/*   Updated: 2022/11/29 15:17:47 by lbarrene         ###   ########.fr       */
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

/*push_swap functions*/
void	ft_swap(t_list *list);
t_list	*ft_push(t_list *from, t_list *to);
void	ft_r_rotate(t_list *list);
void	ft_rotate(t_list *list);

/*struct functions*/
t_head	*ft_addhead(void);
t_list	*ft_addnew(int arg);
void	ft_insertend(t_head *list, int arg);
void	ft_insertinit(t_list *list, int arg);
void	free_str_list_exit(t_head *list, char **str, int len);

#endif