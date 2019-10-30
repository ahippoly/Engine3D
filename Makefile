# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 13:58:07 by ceaudouy          #+#    #+#              #
#    Updated: 2019/10/25 15:35:45 by ceaudouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/
SRC_NAME = main.c\
		   bresenham.c\
		   bresenham_vert.c\
		   bresenham3.c\
		   bresenham4.c\
		   error.c\
		   gere_key.c\
		   editor.c\
		   editor_draw.c\
		   write_file.c\
		   error_edit.c\
		   edit_color.c\
		   draw_back.c\
		   select.c\
		   delete_line.c\
		   gere_key.c\
		   init.c

OBJ_PATH = objs/
INC_PATH = includes/
INC_NAME = color.h\
		   keyboard.h

LIB_PATH = libft
SDL_PATH = SDL2.framework/headers
PRINTF_PATH = libft/ft_printf
GEN = $(addprefix $(GEN_PATH),$(GEN_NAME))
CPPFLAGS = -I$(INC_PATH) -I$(LIB_PATH) -I$(PRINTF_PATH) -I$(SDL_PATH)
LDLIBS = -Llibft -lft
LDLIBX = -LSDL2.framework
SDL_CMP = `sdl2-config --cflags --libs`
FRAMEWK = -framework SDL2
NAME = doom-nukem
CC = clang
CFLAGS = -Wall -Werror -Wextra #-O2 -ffreestanding -fno-builtin
GCOV = -fprofile-arcs -ftest-coverage #--coverage
OBJ_NAME = $(SRC_NAME:.c=.o)
PLIST= $(SRC_NAME:.c=.plist)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

.PHONY: all, clean, fclean, re, norme, cleanlib, analyzer

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	$(CC) $(LDFLAGS) $(LDLIBS) $(LDLIBX) $(SDL_CMP) $^ -o $@

$(OBJ): $(INC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean: clean_gcov
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

gcov_debug: $(SRC)
	@make -C $(LIB_PATH)
	@make -C $(SDL_PATH)
	$(CC) $(LDFLAGS) $(LDLIBS) $(LDLIBX) $(FRAMEWK) $(CPPFLAGS) $(GCOV) $^ -o $(NAME)

clean_gcov:
	rm -fv *.gcov *.gcda *.gcno

re_gcov: clean_gcov fclean gcov_debug

norme:
	norminette $(SRC)
	norminette $(INC)

cleanlib:
	@make -C $(LIB_PATH) fclean
	@make -C $(SDL_PATH) clean

analyzer:
	$(CC) -fsyntax-only $(CFLAGS) $(CPPFLAGS) $(SRC)
	$(CC) --analyze $(CFLAGS) $(CPPFLAGS) $(SRC)

clean_analyzer:
	rm -fv $(PLIST)

ifeq (create_map,$(firstword $(MAKECMDGOALS)))
ARGS = $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
$(eval $(ARGS):;@:)
else
ARGS = test
$(eval $(ARGS):;@:)
endif