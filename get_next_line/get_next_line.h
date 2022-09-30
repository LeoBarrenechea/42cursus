/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:13:55 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/30 17:32:18 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

/*principal-function*/
char		*get_next_line(int fd);

/*utils*/
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *arg);
char		*ft_strrchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif