/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:13:22 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/06 16:36:25 by lbarrene         ###   ########.fr       */
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

/*stack struct*/
typedef struct s_list
{
	int				num;
	struct s_list	*next;
}			t_list;

typedef struct s_head
{
	t_list		*peek;
	void		*high;
	void		*less;
	int			len;
}			t_head;

/*libft function*/
int		ft_atoi(char *str, t_head *ptr);
char	**ft_split(char const *s, char c, t_head *peek);

/*push_swap functions*/
void	alg_of_3(t_head *list_a);
int		ft_strlen(const char *arg);
void	arg_str(char **av, t_head *peek);
t_head	*ft_full_list(int ac, char **av);
void	check_insert(char *av, t_head *peek);
void	free_str_list_exit(t_head *list, char **str, int len);

/*struct functions*/
t_head	*ft_addhead(void);
t_list	*ft_addnew(int arg);
void	ft_swap(t_head *list, int num);
int		check_sort(t_head *peek);
void	ft_rotate(t_head *list, int num);
void	ft_r_rotate(t_head *list, int num);
void	ft_insertend(t_head *head, int arg);
void	ft_insertinit(t_list *list, int arg);
void	ft_push(t_head *from, t_head *to, int num);
void	check_dup(t_head *list, int num, char **str);

#endif