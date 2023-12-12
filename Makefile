# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 19:21:04 by guortun-          #+#    #+#              #
#    Updated: 2023/12/12 20:56:14 by guortun-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
