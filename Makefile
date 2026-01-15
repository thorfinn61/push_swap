# =======================
# Variables
# =======================

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDES    = -Iincludes -Ift_printf

SRCS        = srcs/parser.c \
              srcs/utils/parser_utils.c \
              srcs/stack.c \
			  srcs/utils/stack_utils.c \
              srcs/utils/error.c \
			  srcs/utils/split.c \
			  srcs/utils/bench.c \
              srcs/instructions/swap.c \
              srcs/instructions/push.c \
              srcs/instructions/rotate.c \
              srcs/instructions/rrotate.c \
			  srcs/sort/sort_adaptive.c \
			  srcs/sort/simple/sort_simple.c \
			  srcs/sort/medium/sort_medium.c \
			  srcs/sort/medium/chunk_sort.c \
			  srcs/sort/medium/chunk_array.c \
			  srcs/sort/medium/chunk_ops.c \
			  srcs/sort/complex/sort_complex.c \
			  srcs/sort/complex/quick_utils.c \
			  srcs/sort/complex/quick_base.c \
			  srcs/disorder.c \
			  ft_printf/ft_printf.c \
			  ft_printf/utils.c

MAIN_SRC    = srcs/main.c
BONUS_SRC   = bonus/checker.c

OBJS        = $(SRCS:.c=.o)
MAIN_OBJ    = $(MAIN_SRC:.c=.o)
BONUS_OBJ   = $(BONUS_SRC:.c=.o)

# =======================
# Rules
# =======================

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME)

bonus: $(OBJS) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJ) -o checker

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(MAIN_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re
