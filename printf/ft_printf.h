/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:04:24 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/12 16:32:01 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_itoa(int n);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		print_dec(int dec);
int		print_str(char *arg);
int		ft_atoi(const char *str);
int		print_unsig(unsigned int num);
int		ft_putnbr_unsig(unsigned int n);
int		ft_printf(char const *arg, ...);
int		print_hex(unsigned long int num, char c);

#endif