#asigned names

NAME = libft.a
OBJECTS = *.o
FLAGS = -Wall -Werror -Wextra
CC = gcc -c $(FLAGS) *.c
AR = ar -crs $(NAME) $(OBJECTS)

#functions

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR)

$(OBJECTS): *.c
	$(CC)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME) $(OBJECTS)

re: fclean all

.phony: all clean fclean re


	

