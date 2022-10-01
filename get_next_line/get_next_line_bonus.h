/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:20:32 by lbarrene          #+#    #+#             */
/*   Updated: 2022/10/01 23:44:37 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

/*principal-function*/
char	*get_next_line(int fd);
char	*read_fd(int fd, char *save);
char	*save_next_line(char *lines);
char	*get_lines(char *line);

/*utils*/
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *arg);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif