# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjessi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 14:27:09 by fjessi            #+#    #+#              #
#    Updated: 2020/02/25 14:27:11 by fjessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = push_swap

INCLUDES = push_swap.h

SRC = exit_error.c \
	push_swap.c \
	validation.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJ)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L libftprintf -lft

$(OBJ): %.o : %.c push_swap.h
		gcc -Wall -Werror -Wextra -I $(INCLUDES) -c $<

lib:
	make  -C ./ft_printf

clean:
	/bin/rm -f $(OBJS)
	make -C ./ft_printf clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./ft_printf fclean

re: fclean all
