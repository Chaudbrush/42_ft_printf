# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:31:07 by vloureir          #+#    #+#              #
#    Updated: 2025/05/13 12:54:49 by vloureir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Werror -Wextra

SRC := ft_printf.c ft_print_int.c ft_print_stars.c

OBJ := $(SRC:.c=.o)

INC := ft_printf.h

RM := rm -f

AR := ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $< -I.

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
