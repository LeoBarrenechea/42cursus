/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:13:55 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/26 00:17:53 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

static char	*read_fd(int fd, char *saved);
char	    *get_next_line(int fd);
char	    *ft_strdup(const char *s1);
char        *ft_strjoin(char const *s1, char const *s2);
size_t	    ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	    *ft_strrchr(const char *str, int c);

#endif