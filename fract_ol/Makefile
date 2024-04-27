NAME = fract_ol
SOURCES = utilse.c utilse2.c fractol.c  atod.c hooks.c hooksburningship.c burningship.c mandelbrot.c julia.c
OBJECTS = utilse.o utilse2.o fractol.o  atod.o hooks.o hooksburningship.o burningship.o mandelbrot.o julia.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re