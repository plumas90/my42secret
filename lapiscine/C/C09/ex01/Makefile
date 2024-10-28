NAME = libft.a

MY_SOURCES = ./srcs/ft_putchar.c \
	     ./srcs/ft_putstr.c \
	     ./srcs/ft_swap.c \
	     ./srcs/ft_strlen.c \
	     ./srcs/ft_strcmp.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I./includes
all : $(NAME)

$(NAME) : $(MY_OBJECTS)
	@echo "make $(NAME)"
	ar rcv $(NAME) $(MY_OBJECTS)

%.o: %.c
	@echo "compiling"
	cc $(CFLAGS) -c $< -o $@

clean:
	echo "clean"
	rm -f $(MY_OBJECTS)

fclean: clean
	echo "remove lib file"
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
