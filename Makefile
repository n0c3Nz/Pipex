NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./src/libft -lft -L./src/printf -lftprintf

SRC = main.c ./include/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./src/libft
	$(MAKE) -C ./src/printf
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	$(MAKE) -C ./src/libft clean
	$(MAKE) -C ./src/printf clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ./src/libft fclean
	$(MAKE) -C ./src/printf fclean
	rm -f $(NAME)

re: fclean all
