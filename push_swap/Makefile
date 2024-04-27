NAME = push_swap
NAME_BONUS = checker

SOURCES = errors.c ft_split.c operations_both.c operations.c \
			print_moves.c pushswap.c utilise.c utilise2.c utilise3.c \
			utilisenode.c longest.c utilise_longest.c\
			utilisenode2.c push_to_b.c utilise_topush.c\
			utilise_topush2.c push_to_a.c utilise_to_push_a.c\
			final_sort.c utilise_to_push3.c comarison.c
SOURCES_BONUS =  get_next_line.c get_next_line_utils.c checker_bonus.c \
				operations_bonus.c operations_bonus2.c \
				print_moves_bonus.c utilise_bonus.c utilise_bonus2.c \
				utilise_bonus3.c utilise_node_bonus.c error_bonus.c \
				ft_split.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re