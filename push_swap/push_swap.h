/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:13:22 by lbarrene          #+#    #+#             */
/*   Updated: 2022/12/08 18:10:26 by lbarrene         ###   ########.fr       */
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
	t_list		*high;
	t_list		*min;
	t_list		*lstnum;
	int			posmin;
	int			poshigh;
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
void	first_pos_moves(t_head *list, int pos);
void	alg_of_5(t_head *list_a, t_head *list_b);
void	free_str_list_exit(t_head *list, char **str, int len);
void	check_position(t_head *list, t_list *min, t_list *high);
void	split_from_pivot(t_head *from, t_head *to, t_list *pivot, int num);

/*struct functions*/
t_head	*ft_addhead(void);
t_list	*ft_addnew(int arg);
int		check_sort(t_head *peek);
void	ptr_lst_num(t_head *list);
void	higher_min_num(t_head *list);
void	ft_swap(t_head *list, int num);
void	ft_rotate(t_head *list, int num);
void	ft_r_rotate(t_head *list, int num);
void	ft_insertend(t_head *head, int arg);
void	ft_insertinit(t_list *list, int arg);
void	ft_push(t_head *from, t_head *to, int num);
void	check_dup(t_head *list, int num, char **str);

#endif