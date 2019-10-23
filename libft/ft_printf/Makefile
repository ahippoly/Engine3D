# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiesse <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:49:59 by msiesse           #+#    #+#              #
#    Updated: 2018/12/11 11:28:41 by msiesse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
CFLAGS= -Wall -Wextra -Werror -Ofast
CC= gcc
SRC= aff.c ft_atoi.c ft_gputnbr.c ft_pow.c ft_printf.c ft_putchar_params.c \
	 ft_putfloat.c ft_putnbr_params.c ft_putstr_params.c ft_strlen.c \
	 ft_u_gputnbr.c ft_u_putnbr.c parsor.c parsor_spec.c print_addr.c \
	 print_char.c print_float.c print_int.c print_string.c print_unsigned.c \
	 is_ok.c
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

.c.o:
	$(CC) -c $^ -o $@ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o

fclean: clean
	rm -f libftprintf.a

re: fclean all
