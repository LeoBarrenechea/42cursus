#asigned names

NAME = libft.a

SRCS = ft_isalnum.c ft_isprint.c ft_memcmp.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_tolower.c \
					ft_strnstr.c ft_bzero.c ft_isascii.c \
					ft_memmove.c ft_strlen.c ft_strrchr.c \
					ft_toupper.c ft_isdigit.c ft_memchr.c ft_memset.c \
					ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c

RM = rm -f

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

OBJS = $(SRCS:.c=.o)

AR = ar rcs

#functions

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re bonus


	

