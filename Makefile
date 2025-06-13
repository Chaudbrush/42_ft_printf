# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:31:07 by vloureir          #+#    #+#              #
#    Updated: 2025/06/13 22:47:41 by vloureir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --silent
endif

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Werror -Wextra

SRC := src/ft_printf.c src/ft_print_int.c src/ft_print_stars.c

OBJ := $(SRC:.c=.o)

INC := -Iincludes

HEADER := includes/ft_printf.h

RM := rm -f

AR := ar -rcs

RED := \033[1;30;41m

GREEN := \033[1;30;42m

OFF := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $(OBJ)
	@echo "$(GREEN) Library Crated $(OFF)"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED) Library Deleted $(OFF)"

re: fclean all
