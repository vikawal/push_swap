NAME = push_swap
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
SRCS = \
checking_input.c \
stack_operations.c \
instructions.c \
operations_1_sa.c \
operations_2_pa.c \
operations_3_rr.c \
operations_4_rrr.c \
errors_clean.c \
push_swap_main.c \
sorting.c \
sort_choose.c \
sort_help.c




OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./LIBFT
LIBFT = $(LIBFT_PATH)/libft.a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(LIBFT)

fclean: clean
	rm -f $(NAME) 

re: fclean all

# test: all
# 	./$(NAME)


.PHONY: all clean fclean re test