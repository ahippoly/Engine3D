/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:40:31 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/09/03 14:07:46 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include "color.h"
# include "keyboard.h"
# include <math.h>
# include <time.h>
# include <pthread.h>

# define NAME "WOLF3D by SKR SKRUUUU"
# define W_WIN 960
# define H_WIN 600
# define W_IMG 960
# define H_IMG 600
# define H_MAP 192
# define W_MAP 192

/*
** Masks ###################################
*/

# define KP_MASK (1L << 0)
# define KR_MASK (1L << 1)
# define EXP_MASK (1L << 15)
# define CROSS_MASK (1L << 17)
# define MOVE_MASK (1L << 6)
# define MP_MASK (1L << 2)
# define MR_MASK (1L << 3)

/*
** ########################################
*/

/*
** Window / img ###########################
*/

# define N_IMG 1

/*
** ######################################
*/

/*
** errors mlx ###########################
*/

# define ERR_MLX_INIT 1
# define ERR_MLX_WINDOW 2
# define ERR_MLX_IMG 3
# define ERR_MLX_IDATA 4

/*
** #####################################
*/

/*
** pixels #############################
*/

# define X 0
# define Y 1

/*
** ####################################
*/

/*
** threads ############################
*/

# define N_THREAD 4

/*
** ###################################
*/

/*
** Parsor ############################
*/

# define ERR_NB_TOOBIG 2
# define ERR_DIM_MAP 3
# define ERR_CHAR 4
# define ERR_TOOSMALL 5
# define ERR_TOOBIG 6
# define ERR_WALL 7
# define COM -42

/*
** ##################################
*/

/*
** Constantes maths ########################
*/

# define C_SHDOW 8.0

/*
** ############################################
*/

typedef int			t_bool;
typedef union		u_double
{
	double			x;
	unsigned long	x_l;
}					t_double;

typedef	struct		s_points
{
	t_dint			x;
	t_dint			y;
	t_dint			z;
}					t_points;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_map;
	char			*data;
	char			*data_map;
	int				bpp;
	int				sline;
	int				end;
}					t_mlx;

typedef struct		s_tex
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sline;
	int				end;
	int				height;
	int				width;
}					t_tex;

typedef struct		s_parsor
{
	int				cmd;
	char			nb[16];
	int				index_nb;
	int				cols;
	int				lines;
}					t_parsor;

typedef struct		s_env
{
	int				height_map;
	double			radian;
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				z;
	int				fd;
	double			ya;
	double			xa;
	double			ay;
	double			ax;
	double			bx;
	double			xb;
	double			by;
	double			yb;
	double			ynew;
	double			xnew;
	double			bynew;
	double			bxnew;
	int				xold;
	int				yold;
	int				bxold;
	int				byold;
	double			view;
	double			i;
	double			dist;
	double			wall;
	int				side;
	int				cordinal_hor;
	int				cordinal_ver;
	int				mapy;
	int				mapx;
	int				t_x1;
	int				t_y1;
	double			corr_dist;
	double			pos_hor;
	double			pos_ver;
	double			delta_dist;
	double			delta_x;
	double			delta_y;
	double			x_floor;
	double			y_floor;
	int				**tex_wall;
	int				cols;
	int				lines;
	double			pos_x;
	double			pos_y;
	double			axe;
	int				speed;
	t_bool			forward;
	t_bool			backward;
	t_bool			right;
	t_bool			left;
	int				rand;
	int				rain;
	t_mlx			m;
	t_tex			tex[9];
	t_points		points;
	t_parsor		parsor;
	pthread_t		thread[N_THREAD + 1];
	int				n_th;
	double			sensi;
}					t_env;

void				env_init(t_env *e);
int					wolf3d(t_env *e);
void				ft_read(t_env *e);
void				check_error(char *str, t_env *e);
int					ft_expose(t_env *e);
int					open_file(char *path);

/*
** Draw functions ##################################################
*/

void				minimap(t_env *e);
void				ft_draw(t_env *e);
void				texture_wall(t_env *e);
void				rain(t_env *e);

/*
** #####################################################################
*/

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
** Raycasting functions ##################################################
*/

void				search_walls(t_env *e);
void				detection_hor(t_env *e);
void				detection_ver(t_env *e);
void				finding_wall(t_env *e);

/*
** #####################################################################
*/

/*
** Moove functions ##################################################
*/

void				forward(t_env *e);
void				back(t_env *e);
void				check_moove(t_env *e);
void				check_moove_back(t_env *e);
void				check_moove2(t_env *e);
void				check_moove_back2(t_env *e);

/*
** #####################################################################
*/

/*
** Parsor functions ##################################################
*/

char				parsor_com(const int fd);
void				parsor_lcol(const int fd, t_env *e);
void				init_parsor(t_parsor *parsor);
void				error_parsor(int err_id, t_points *points);
int					get_nb(const char *nb);
void				w_parsor(const int fd, t_env *e);
void				parsor_map(const int fd, t_env *e);
void				parsor_cam(const int fd, t_env *e);
void				verif_charnb(char c, t_env *e);

/*
** #####################################################################
*/

/*
** Points functions ####################################################
*/

void				init_points(t_points *points);
void				reinit_points(t_points *points);
int					get_z(t_points *points, t_env *e);
int					get_bz(t_points *points, t_env *e);
int					moove_get_z(t_points *points, t_env *e, int x, int y);

/*
** #######################################################################
*/

/*
** Hook functions #########################################################
*/

int					gere_key(int key, t_env *e);
int					release_key(int key, t_env *e);
int					do_exit(t_env *e);

/*
** #######################################################################
*/

/*
** Draw functions
*/

void				fill_pixel(char *img_data, int x, int y, int color);
void				fill_pixel_map(char *img_data, int x, int y, int color);
void				draw_col(t_env *e);
void				fill_texture_wall(int x, int y, t_env *e);
void				fill_texture_floor(int x, int y, t_env *e);
void				fill_texture_sky(int x, int y, t_env *e);
void				init_draw(t_env *e, int n_th);

/*
** Utilities functions ###################################################
*/

void				good_exit(t_env *e);
double				ceil_func(double num, double ceil);
void				error_thread_create(t_env *e);
void				error_thread_join(t_env *e);

/*
** #########################################################################
*/

#endif
