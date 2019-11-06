/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 08:24:06 by ahippoly          #+#    #+#             */
/*   Updated: 2019/10/17 17:52:58 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "include/SDL2/SDL.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

# define WIN_SIZE 800
# define MINI_MAP_X 650
# define MINI_MAP_Y 50
# define MINI_MAP_W 100
# define MINI_MAP_H 100
# define PERSO 5
# define BUFF_SIZE 1000000
# define NAZI "Alerte nazi, Test de nazi detecte, Alerte nazi\n"

typedef struct  s_pos
{
    double         x;
    double         y;
}               t_pos;

typedef struct  s_vox
{
    double         x;
    double         y;
    double         z;
}               t_vox;

typedef struct  s_line
{
	SDL_Point	pos1;
	SDL_Point	pos2;
	double		text_ratio;
}               t_line;

typedef struct	s_text
{
	char		*pixels;
	int			w;
	int			h;
	int			bpp;
}				t_text;

typedef struct  s_vox_line
{
	t_vox pos1;
	t_vox pos2;
}				t_vox_line;

typedef struct  s_var
{
	SDL_Window *win;
    SDL_Renderer *rend;
	SDL_Texture *screen;
	SDL_Texture *mini_map_xy;
	SDL_Texture *mini_map_xz;
	SDL_Texture *mini_map_yz;
	SDL_Texture *character;
	SDL_Texture *t_ray;
	char *p_tab;;
	char *p_ray;
	char *p_clear;
	char p_perso[PERSO*PERSO*4];
	char ***map;
	t_vox perso_pos;
	t_vox map_size;
	double z_pos;
	SDL_Rect map_border;
	SDL_Point win_size;
	double rot;
	double roty;
	double fov;
	t_text stone;
	char *img_tab;
	SDL_Point img_size;
}               t_var;

typedef struct  s_oct
{
    int         inc[2];
    int         d[2];
    int         e;
    int         bool;
    int         boolxy;
    int         ecart;
}               t_oct;

typedef struct  s_memline
{
	int 		length;
	SDL_Point	*pos;
}				t_memline;

typedef struct  s_disp_range
{
	double		start_x;
	double		start_y;
	double		end_y;
	double		end_x;
}				t_disp_range;

char *ft_load_bmp(char *file, int *width, int *height);
void errorcase(void);

void    oct_ini(t_oct *oct, SDL_Point pos1, SDL_Point pos2, int pos[2][2], int forced_side);
void    octant(SDL_Point pos1, SDL_Point pos2, char *pixel, int color, int forced_side);

void put_border(char *p_tab, SDL_Point disp_size);
void put_rect(char *pixel, SDL_Point pos, SDL_Point size, int color, SDL_Point win_size);
void map_ini(char ***map, SDL_Point size, t_var *v);
void print_map(t_var *v);
void load_wall(t_var *v);
SDL_Point load_corner(t_var *v, int i, int j, int h);

void load_triangle1_plane(t_var *v, int x, int y, int z , SDL_Point corner[4]);
void load_triangle_point(t_var *v, int x, int y, int z, int rot);

char ***readfile2(char *file, t_var *v);

void disp_text(char *pixels, char *img_tab, SDL_Point size);

SDL_Point   *mem_octant(SDL_Point pos1, SDL_Point pos2, int *length, int forced_side);
void    	*nazi_case(void);
void		draw_texture(t_line top, t_line bot, char *pixels, t_text *text);
void   		bresenham_texture(t_line line, char *pixels, t_text *text, double x_ratio, t_disp_range ra);
SDL_Point   vox_on_screen(t_vox point, t_vox cam_pos, t_pos cam_rot);

t_vox cut_frustum(t_vox cam_pos, t_pos cam_rot);
//t_pos line_intersect(t_vox cam_pos, t_pos cam_rot);
t_disp_range adapt_out_screen(SDL_Point *pp1, SDL_Point *pp2, int for_xy);

SDL_Point segment_intersect(SDL_Point p1, SDL_Point p2, SDL_Point p3, SDL_Point p4);
void line_intersect(t_vox cam_pos, t_pos cam_rot, t_vox *p1, t_vox *p2, t_line *line);
t_line create_3Dlines(t_vox cam_pos, t_pos cam_rot, t_vox p1, t_vox p2);
t_vox create_vox(double x, double y, double z);
SDL_Point create_point(int x, int y);
#endif