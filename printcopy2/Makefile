NAME = libftprintf.a
LIBFT = ./libft

MY_SOURCES = ft_print.c \
	     ft_print_char.c \
	     ft_print_decimal.c \
	     ft_print_hex.c \
	     ft_print_str.c \
	     ft_print_unsigned_decimal.c \
	     ft_print_voidptr.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	make -C $(LIBFT) bonus
	cp libft/libft.a $@
	ar rc $(NAME) $(MY_OBJECTS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT) clean
	rm -f $(MY_OBJECTS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
