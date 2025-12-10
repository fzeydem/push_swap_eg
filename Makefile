NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iinclude
SRC			= src/main.c \
			  src/utils.c \
			  src/utils_split.c \
			  src/stack.c \
			  src/parse.c \
			  src/indices.c \
			  src/check_sorted.c \
			  src/ops_swap.c \
			  src/ops_push.c \
			  src/ops_rotate_up.c \
			  src/ops_rotate_down.c \
			  src/sort_small_a.c \
			  src/sort_small_b.c \
			  src/sort_quick.c
OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
