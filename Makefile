# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 13:58:07 by ceaudouy          #+#    #+#              #
#    Updated: 2019/11/08 14:07:19 by ceaudouy         ###   ########.fr        #
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
TTF_PATH = SDL2_ttf.framework/headers
FREETYPE = SDL2_ttf.framework/FreeType.framework/headers/freetype
PRINTF_PATH = libft/ft_printf
GEN = $(addprefix $(GEN_PATH),$(GEN_NAME))
CPPFLAGS = -I$(INC_PATH) -I$(LIB_PATH) -I$(PRINTF_PATH) -I$(SDL_PATH) -I$(TTF_PATH) -I$(FREETYPE)
LDLIBS = -Llibft -lft
LDLIBX = -LSDL2.framework
LDLIBX_TTF = -LSDL2_ttf.framework
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

.PHONY: all, clean, fclean, re, norme, cleanlib

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	$(CC) $(LDFLAGS) $(SDL_CMP) $(LDLIBS) $(LDLIBX) $(LDLIBX_TTF) $^ -o $@

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
	norminette $(SRC)
	norminette $(INC)

cleanlib:
	@make -C $(LIB_PATH) fclean
	@make -C $(SDL_PATH) clean
