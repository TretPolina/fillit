NAME = fillit

SRC = create_block_tetr.c create_field.c ft_putchar.c ft_putstr.c main.c move_alf.c movements_on_field.c solver.c validation.c size_field.c

OBJ = $(SRC:.c=.o)

INCLUDE = fillit.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all