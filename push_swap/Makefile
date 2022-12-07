# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 13:37:19 by lbarrene          #+#    #+#              #
#    Updated: 2022/12/07 17:36:03 by lbarrene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = alghoritms.c checkers.c free_str_list_exit.c ft_atoi.c \
		ft_moves.c ft_split.c struct_utis.c push_swap.c

RM = rm -f

FLAGS = -Wall -Werror -Wextra

SANIT = -fsanitize=address -g3

CC = gcc $(FLAGS)

OBJS = $(SRCS:%.c=%.o)


all: $(NAME) $@

$(NAME): $(OBJS)
		$(CC) $^ -o $@

clean: 
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

clang: $(OBJS)
		clang $(FLAGS) $(SANIT) $^ -o $(NAME)

re: fclean all

.pony: all clean fclean re
