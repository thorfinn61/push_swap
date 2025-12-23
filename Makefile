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
              srcs/swap.c \
              srcs/push.c \
              srcs/rotate.c \
              srcs/rrotate.c \
              srcs/sort_small.c \

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
