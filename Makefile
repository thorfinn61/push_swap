# =======================
# Variables
# =======================

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDES    = -Iincludes

SRCS        = srcs/parser.c \
			  srcs/main.c \
              srcs/utils/parser_utils.c \
              srcs/stack.c \
              srcs/utils/error.c \
			  srcs/utils/split.c \
              srcs/instructions/swap.c \
              srcs/instructions/push.c \
              srcs/instructions/rotate.c \
              srcs/instructions/rrotate.c \
			  srcs/sort/sort_adaptive.c \
              srcs/sort/sort_small.c \
			  srcs/sort/sort_simple.c \
			  srcs/sort/sort_medium.c \
			  srcs/sort/sort_complex.c \
			  srcs/disorder.c \

OBJS        = $(SRCS:.c=.o)

# =======================
# Rules
# =======================

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
