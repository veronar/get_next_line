# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vesingh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 13:33:16 by vesingh           #+#    #+#              #
#    Updated: 2019/06/18 17:06:19 by vesingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c ft_memset.c ft_bzero.c ft_putchar.c ft_putstr.c ft_strcpy.c ft_memalloc.c ft_putendl.c ft_strcat.c ft_strchr.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strnlen.c ft_strsub.c 

OBJ = $(SRC:.c=.o)

INCL = get_next_line.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) $(OBJ) $(INCL)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
