/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:04:24 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/11 13:18:07 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(char const *arg, ...);
char	print_char_str(char *arg);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		print_dec(int dec);
int		print_hex(unsigned long int num, char c, int fd);
int		print_unsig(unsigned int num);

#endif