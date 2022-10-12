# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 12:55:23 by lbarrene          #+#    #+#              #
#    Updated: 2022/10/12 16:11:16 by lbarrene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putnbr_unsig.c \
	   ft_putnbr.c my_utils.c print_hex.c print_str.c
	   
RM = rm -f

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

OBJS = $(SRCS:.c=.o)

AR = ar rcs

#functions

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) -c $< -o $@
	
$(NAME): $(OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re

