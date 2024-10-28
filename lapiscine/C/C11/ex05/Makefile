NAME = do-op

MY_SOURCES = make_do-op2.c \
	     make_do-op.c 

CFLAGS = -Wall -Wextra -Werror -I./includes
all : $(NAME)

$(NAME) : $(MY_OBJECTS)
	@echo "make $(NAME)"
	cc $(CFLAGS) -o $(NAME) $(MY_SOURCES)

clean:
	echo "clean"
	rm -f $(MY_OBJECTS)

fclean: clean
	echo "remove lib file"
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
