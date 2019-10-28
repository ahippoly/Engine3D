/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom-nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:17:24 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/28 18:15:32 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

/*
** LIBRARIES
*/

#include "libft.h"
#include <stdio.h> // a delete

/*
** MACROS
*/

/*
** parsing
*/

# define ERR_COUNTING 1
# define ERR_DOUBLE_DEF 2
# define ERR_NOT_VALID_STRUCT 4
# define ERR_GET_DATA 5
# define ERR_SYNTAX 6
# define ERR_TOO_BIG_DATA 7
# define ERR_NOT_VALID_VERTEX 8
# define ERR_INDEX 9
# define ERR_NOT_VALID_LINEDEF 10
# define ERR_ALREADY_GET 11
# define ERR_NOT_VALID_SIDEDEF 12

/*
** memory
*/

# define ERR_MEM_LISTS 3

# define LINEDEF 2
# define SIDEDEF 3
# define SECTOR 1
# define VERTEX 0

/*
** TYPEDEFS/STRUCTS
*/

typedef unsigned char	t_usshort;
typedef char		t_sshort;
typedef unsigned short	t_ushort;
typedef t_darr		t_dvertex;
typedef t_darr		t_dsidedef;
typedef t_darr		t_dlinedef;
typedef t_darr		t_dsector;
typedef char		t_bool;
typedef float		t_mat;

typedef struct		s_vertex
{
	float			x;  // ou short	x
	float			y;  // ou short	y
	float			z;  // ou short z
}					t_vertex;

typedef struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef struct		s_base
{
	t_vect			ux;
	t_vect			uy;
	t_vect			uz;
}					t_base;

typedef struct		s_sidedef
{
//	float			x_offset; //ou short x_offset
//	float			y_offset; //ou short y_offset
	short			up_texture;
	short			low_texture;
	short			middle_texture;
	unsigned short	sector_id;
	t_vect			v_n;
	unsigned short	linedef_id;
	void			*data;
	int			size_data;
}					t_sidedef;


typedef struct		s_linedef
{
	unsigned short		start;
	unsigned short		end;
	t_vect			v_l;
	short	flags; // pas obligatoire a priori mais a voir
	short	type;
	short	sector_tag;
	short	right_sidedef;  //Obsolete si pointeur sur les sidedefs
	short	left_sidedef;
}					t_linedef;


typedef struct		s_sector
{
	short			floor_height;
	short			ceil_height;
	short			floor_texture;
	short			ceil_texture;
	short			light_lvl;
	unsigned short	type; // defini le type de secteur, est-ce qu'il y a de la brume, du poison, etc...
	unsigned short	sector_tag; /* defini une possibilie d'action avec une linedef qui possede le meme sector_tag
								example: plus de luminosite des qu'on a realise une action sur un mur */
	unsigned short	start_sidedef;
	unsigned short	end_sidedef;
}					t_sector;

typedef struct		s_cam
{
	t_base		base; // la base qui sera utilise pour exprimer les coordonnes des objets
	t_vertex	pos; // la pos dans le repere classique
	t_vect		view; // le facteur k se trouve dans ce vecteur
}					t_cam;

typedef struct		s_portal
{
	unsigned short		sidedef_root;
	unsigned short		sidedef_dest;
}					t_portal;

typedef struct		s_seg
{
	t_vertex		start;
	t_vertex		end;
	t_sidedef		*sidedef;
	t_linedef		*linedef;
	t_sector		*front;
	t_sector		*back;
}					t_seg;

typedef struct		s_bspnode
{
	short			x;
	short			y;
	short			dx;
	short			dy;
	short			bbox[2][4];
	t_ushort		children[2];
}			t_node;

typedef struct		s_parsor
{
	int		fd;
	t_darr		vertex_occ;
	t_darr		sidedef_occ;
	t_darr		linedef_occ;
	t_darr		sector_occ;
	t_bool		check_n[4];
	int		total_check;
	int		what_check;
	char		pos;
}			t_parsor;

typedef struct		s_env
{
	t_vertex	*vertex_list;
	t_sidedef	*sidedef_list;
	t_linedef	*linedef_list;
	t_sector	*sector_list;
	int		n_list[4];
	t_parsor	parsor;
	t_cam		cam[8];
}			t_env;

/*
** FUNCTIONS
*/

/*
** Parsor functions
*/

void			doom_parsor(t_env *e);
t_bool			check_numbers(t_env *e);
t_bool			get_doom_data(t_env *e);
t_bool			get_vertex(t_env *e);
int			get_the_number(t_env *e);
t_bool			get_linedef(t_env *e);
t_bool			get_sector(t_env *e);
t_bool			get_sidedef(t_env *e);
t_bool			is_saved(int index, t_darr d_arr);

/*
** Utilities functions
*/

void			exit_error(t_env *e, int id, const char *msg);
void			init_env(t_env *e);

#endif
