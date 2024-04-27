NAME = libftprintf.a
SOURCES = \
	ft_printf.c printn_base.c putnbr_com.c
OBJECTS = \
	ft_printf.o printn_base.o putnbr_com.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(OBJECTS)
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
