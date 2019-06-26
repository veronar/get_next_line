# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vesingh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 13:33:16 by vesingh           #+#    #+#              #
#    Updated: 2019/06/26 14:41:44 by vesingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

SRC = get_next_line.c main.c

INCL = get_next_line.h

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) ./libft/libft.a

clean:
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
