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

NAME_PUSH = push_swap
NAME_CHECKER = checker

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC_PS = print_stack.c simple_alg.c no_simple_alg.c middle_alg.c \
		advanced_alg_p1.c advanced_alg_p2.c advanced_alg_p3.c advanced_alg_p4.c\
		advanced_alg_p5.c advanced_alg_p6.c s_instruction.c p_instruction.c \
		rr_instruction.c rrr_instruction.c instruction.c exit_error.c \
		push_swap.c validation.c check_repeat.c making_stack.c \
		sort_massiv.c get_index.c delete_head.c \

SRC_CH = print_stack.c s_instruction.c p_instruction.c rr_instruction.c \
		rrr_instruction.c instruction.c exit_error.c checker.c validation.c \
		check_repeat.c making_stack.c sort_massiv.c get_index.c \
		delete_head.c \

OBJ_PS = $(SRC_PS:.c=.o)

OBJ_CH = $(SRC_CH:.c=.o)

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRCS_PS = $(addprefix $(SRC_DIR)/,$(SRC_PS))
SRCS_CH = $(addprefix $(SRC_DIR)/,$(SRC_CH))
OBJS_PS = $(addprefix $(OBJ_DIR)/,$(OBJ_PS))
OBJS_CH = $(addprefix $(OBJ_DIR)/,$(OBJ_CH))

# COLORS

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
AQUAMARINE = \033[0;36m
GRAY = \033[0;37m

BOLD_RED = \033[1;31m
BOLD_GREEN = \033[1;32m
BOLD_YELLOW = \033[5;33m
BOLD_BLUE = \033[1;34m
BOLD_PURPLE = \033[1;35m
BOLD_AQUAMARINE = \033[1;36m

RESET = \033[0m

all:$(NAME_PUSH) $(NAME_CHECKER)
	@echo "$(BOLD_GREEN)Ready! Let's go to check!$(RESET)"

$(NAME_PUSH): $(OBJS_PS)
	@echo "$(BLINK)$(YELLOW)Sooo....Let's start!$(RESET)"
	@make -C ft_printf
	@$(CC) $(FLAGS) -o $(NAME_PUSH) $(OBJS_PS) -L ft_printf -lftprintf
	@echo "$(BOLD_PURPLE)PUSH_SWAP is ready!$(RESET)"
	@echo "$(AQUAMARINE)To be continue...$(RESET)"

$(NAME_CHECKER): $(OBJS_CH)
	@make -C ft_printf
	@$(CC) $(FLAGS) -o $(NAME_CHECKER) $(OBJS_CH) -L ft_printf -lftprintf
	@echo "$(BOLD_PURPLE)CHECKER is ready!$(RESET)"
	@echo "$(AQUAMARINE)To be continue...$(RESET)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@echo "$(BOLD_BLUE)CLean...$(RESET)"
	@make clean -C ft_printf
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(BOLD_BLUE)FCLean...$(RESET)"
	@/bin/rm -f $(NAME_PUSH)
	@/bin/rm -f $(NAME_CHECKER)
	@make fclean -C ft_printf

re: fclean all