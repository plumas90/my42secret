NAME = pipex

MY_SOURCES = main.c \
	     util1.c \
	     util_free.c \
	     utilsplit.c \



CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

MY_OBJECTS = $(MY_SOURCES:.c=.o)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@
	
$(NAME): $(MY_OBJECTS)
	cc $(CFLAGS) $(MY_OBJECTS) -o pipex

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
