# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiesse <msiesse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 22:26:21 by msiesse           #+#    #+#              #
#    Updated: 2019/10/09 13:49:46 by msiesse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/
SRC_NAME = 	parsor.c\
		manage_error.c\
		check_numbers.c\
		main.c\
		init_env.c

OBJ_PATH = objs/
INC_PATH = includes/
INC_NAME =	doom-nukem.h
LIB_PATH = libft
PRINTF_PATH = libft/ft_printf
CPPFLAGS = -I$(INC_PATH) -I$(LIB_PATH) -I$(PRINTF_PATH)
LDLIBS = -Llibft -lft
NAME = doom-nukem
CC = clang
CFLAGS = -Wall -Werror -Wextra -O2 -ffreestanding -fno-builtin
SANITIZE= -fsanitize=address -g3
OBJ_NAME = $(SRC_NAME:.c=.o)
PLIST= $(SRC_NAME:.c=.plist)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

.PHONY: all, clean, fclean, re, norme, cleanlib, analyzer

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ): $(INC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC_PATH)
	norminette $(INC_PATH)
	norminette $(LIB_PATH)

cleanlib:
	@make -C $(LIB_PATH) fclean

analyzer:
	$(CC) -fsyntax-only $(CFLAGS) $(CPPFLAGS) $(SRC)
	$(CC) --analyze $(CFLAGS) $(CPPFLAGS) $(SRC)

clean_analyzer:
	rm -fv $(PLIST)

fclean_all: fclean cleanlib
