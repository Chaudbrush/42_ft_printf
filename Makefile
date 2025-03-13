
NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := ft_printf.c ft_print_int.c ft_print_string.c
OBJ := $(SRC:.c=.o)
INC := ft_printf.h
AR := ar -crs
RM := rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

$%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all
