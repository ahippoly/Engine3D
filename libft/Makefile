# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 11:45:15 by msiesse           #+#    #+#              #
#    Updated: 2019/10/14 11:11:03 by ceaudouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
PRINTF= libftprintf.a
CFLAGS= -g -Wall -Wextra -Werror -O3 -ffreestanding -fno-builtin
CC= gcc
HEAD_PF= ./ft_printf
HEAD_LIB= .
SRC= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	 ft_memmove.c ft_memchr.c ft_memcmp.c  \
	 ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	 ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	 ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	 ft_isalpha.c ft_isdigit.c	ft_isalnum.c \
	 ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	 ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	 ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	 ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	 ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	 ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	 ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	 ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strspn.c ft_strcspn.c \
	 ft_strtok.c ft_lstpushback.c get_next_delim.c ft_utoa.c ft_lutoa.c \
	 new_node_buf.c ft_isspace.c err_mem.c ft_tabdel.c ft_fgetc.c \
	 dyn_int.c fgetc_pars.c dyn_float.c ft_dswap.c fpart.c rfpart.c \
	 capitalizer.c ft_swap.c ft_max.c ft_min.c
SRCPF= ft_printf/aff.c ft_printf/ft_atoi.c ft_printf/ft_gputnbr.c \
	   ft_printf/ft_pow.c ft_printf/ft_printf.c ft_printf/ft_putchar_params.c \
	   ft_printf/ft_putfloat.c ft_printf/ft_putnbr_params.c \
	   ft_printf/ft_putstr_params.c ft_printf/ft_strlen.c \
	   ft_printf/ft_u_gputnbr.c ft_printf/ft_u_putnbr.c ft_printf/parsor.c \
	   ft_printf/parsor_spec.c ft_printf/print_addr.c \
	   ft_printf/print_char.c ft_printf/print_float.c ft_printf/print_int.c \
	   ft_printf/print_string.c ft_printf/print_unsigned.c \
	   ft_printf/is_ok.c

OBJ= $(SRC:.c=.o)
OBJ_PF= $(SRCPF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_PF)
	@ar rc $@ $(OBJ) $(OBJ_PF)
	@echo "\033[1;34mlibft is created\033[0m"

.c.o:
	@$(CC) -c $^ -o $@ $(CFLAGS) -I$(HEAD_PF) -I$(HEAD_LIB)

.PHONY: clean

clean:
	rm -f *.o
	rm -f ft_printf/*.o

fclean: clean
	rm -f libft.a

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(SRCPF)
