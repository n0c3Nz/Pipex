# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 23:27:42 by guortun-          #+#    #+#              #
#    Updated: 2023/12/21 23:30:04 by guortun-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
LFLAGS = -L./src/libft -lft -L./src/printf -lftprintf

SRC = main.c ./include/utils.c ./include/splitter_1.c ./include/splitter_2.c

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
