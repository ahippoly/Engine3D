/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:57:54 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/24 11:34:47 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "libft.h"
# include "SDL.h"
# include "color.h"
# include "keyboard.h"
# include <math.h>
# include <time.h>
# include <pthread.h>

# define NAME "DOOM SKR SKRUUUU"
# define W_WIN 960
# define H_WIN 600
# define W_IMG 1920
# define H_IMG 1080
# define H_MAP 192
# define W_MAP 192

typedef	struct		s_sdl
{
	SDL_bool		quit;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Point		point;
	SDL_Event		event;
	SDL_Rect		pos;
	char			*pixels;
}					t_sdl;

typedef	struct		s_env
{
	int				x;
	int				y;

	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;

	int				set_wall;
	int				set_map;
	int				fd;
	char			**file;
	int				i_file;
	int				edit_id;
	int				tmp_id;
	int				i_back;

	int				t_x1;
	int				t_y1;
	int				t_x2;
	int				t_y2;

	SDL_Point		p1;
	SDL_Point		p2;
	SDL_Point		p3;
	SDL_Point		p4;

	SDL_Rect		map;
	
	int				select;
	int				select_line;
	int				line;
	t_sdl			sdl;
}					t_env;

void	error_sdl(t_env *e);
void    gere_key(t_env *e);

/*
** Bresenham functions ##################################################
*/

void				ft_bresenham(t_env *e);
void				ft_bresenham2(t_env *e, float f);
void				ft_octant1(t_env *e, float f);
void				ft_octant2(t_env *e, float f);
void				ft_octant3(t_env *e, float f);
void				ft_octant4(t_env *e, float f);
void				ft_octant5(t_env *e, float f);
void				ft_octant6(t_env *e, float f);
void				ft_octant7(t_env *e, float f);
void				ft_octant8(t_env *e, float f);
void				ft_octant_horleft(t_env *e);
void				ft_octant_vert(t_env *e);
void				ft_octant_vert2(t_env *e);
void				ft_octant_horright(t_env *e);

/*
** #####################################################################
*/

/*
** Editor functions ##################################################
*/

void				editor(t_env *e);
void				write_file(t_env *e);
void				draw_wall(t_env *e);
void				error_edit(t_env *e, char *tmp, char *tmp2);
void				set_color(t_env *e);
void				draw_back(t_env *e);
void				draw_ver(t_env *e);
int					check_redraw(t_env *e);
void				back_pass(t_env *e, int i);
void				edit_draw(t_env *e);
void				fill_pixel(char *pixels, int x, int y, int color);
int					check_crossing(t_env *e);
void				select_mode(t_env *e);
void				take_cord(t_env *e, int i);
SDL_Point			segment_intersect(t_env *e);
int					check_inter(t_env *e, SDL_Point inter);
void				clear(t_env *e);
void				delete_line(t_env *e);
void				error(t_env *e);


/*
** ####################################################################
*/

#endif