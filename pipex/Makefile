NAME = pipex
SOURCES =\
	 the_main.c errors.c check_args.c \
	 ft_split.c ft_strlcpy.c utilse.c for_execve.c
OBJECTS = \
	the_main.o errors.o check_args.o \
	ft_split.o ft_strlcpy.o utilse.o for_execve.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re