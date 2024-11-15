NAME = push_swap
BONUS = checker

MY_SOURCES = list_util.c \
		 list_util2.c \
		 order1p_s.c \
		 order2r.c \
		 order3rr.c \
		 part1_atoi.c \
		 part1_check_argv.c \
		 part1_mainparsing.c \
		 part2_set_stack.c \
		 part3_set_node.c \
		 part4_atob.c \
		 part4_btoa.c \
		 ft_split.c \
		 ft_split2.c \
		 part4_handmade.c \
	     main_pushswap.c
		 
BONUSE_SOURCES = bonus_get_next_line_utils_bonus.c \
		bonus_get_next_line.c \
		bonus_main.c \
		bonus_pushswap.c \
		bonus_util.c \
		list_util.c \
		list_util2.c \
		order1p_s.c \
		order2r.c \
		order3rr.c \
		part1_atoi.c \
		part1_check_argv.c \
		part1_mainparsing.c \
		part2_set_stack.c \
		part3_set_node.c \
		part4_atob.c \
		part4_btoa.c \
		ft_split.c \
		ft_split2.c \
		part4_handmade.c \


CFLAGS = -Wall -Wextra -Werror 

#-g -fsanitize=address

all: $(NAME)
bonus : $(BONUS)

MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_BONUS = $(BONUSE_SOURCES:.c=.o)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@
	
$(NAME): $(MY_OBJECTS)
	cc $(CFLAGS) $(MY_OBJECTS) -o $(NAME)

$(BONUS): $(MY_BONUS)
	cc $(CFLAGS) $(MY_BONUS) -o $(BONUS)

clean:
	rm -f $(MY_OBJECTS) $(MY_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY: all clean fclean re bonus
