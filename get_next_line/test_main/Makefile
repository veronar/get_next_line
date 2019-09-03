# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modo <modo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 13:33:16 by vesingh           #+#    #+#              #
#    Updated: 2019/09/03 18:28:41 by modo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

SRC = main.c ../get_next_line.c

INCL = ../get_next_line.h

all: $(NAME)

$(NAME):
	make -C .././libft
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) .././libft/libft.a

clean:
	make clean -C .././libft

fclean: clean
	make fclean -C .././libft
	rm -f $(NAME)

re: fclean all
