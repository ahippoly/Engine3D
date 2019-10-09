/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom-nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:17:24 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/08 16:07:10 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

/*
** LIBRARIES
*/

#include "libft.h"

/*
** MACROS
*/

/*
** parsing
*/

# define ERR_COUNTING 1
# define ERR_DOUBLE_DEF 2

# define LINEDEF 0
# define SIDEDEF 1
# define SECTOR 2
# define VERTEX 3

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


typedef struct		s_vertex
{
	float			x;  // ou short	x
	float			y;  // ou short	y
	float			z;  // ou short z
}					t_vertex;


typedef struct		s_sidedef
{
	float			x_offset; //ou short x_offset
	float			y_offset; //ou short y_offset
	char			*up_texture;
	char			*low_texture;
	char			*middle_texture;
	unsigned short	sector_id;
}					t_sidedef;


typedef struct		s_linedef
{
	t_vertex		start;
	t_vertex		end;
	unsigned short	flags; // pas obligatoire a priori mais a voir
	unsigned short	type;
	unsigned short	sector_tag;
	unsigned short	right_sidedef;  //Obsolete si pointeur sur les sidedefs
	unsigned short	left_sidedef;
}					t_linedef;


typedef struct		s_sector
{
	short			floor_height;
	short			ceil_height;
	char			*floor_texture;
	char			*ceil_texture;
	short			light_lvl;
	unsigned short	type; // defini le type de secteur, est-ce qu'il y a de la brume, du poison, etc...
	unsigned short	sector_tag; /* defini une possibilie d'action avec une linedef qui possede le meme sector_tag
								example: plus de luminosite des qu'on a realise une action sur un mur */
}					t_sector;

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
	int		count[4];
	t_bool		check_n[4];
	int		total_check;
	int		what_check;
}			t_parsor;

typedef struct		s_env
{
	t_vertex	*vertex_list;
	t_sidedef	*sidedef_list;
	t_linedef	*linedef_list;
	t_sector	*sector_list;
	int		n_list[4];
	t_parsor	parsor;
}			t_env;

/*
** FUNCTIONS
*/

/*
** Parsor functions
*/

void			doom_parsor(t_env *e);
t_bool			check_numbers(t_env *e);

/*
** Utilities functions
*/

void			exit_error(t_env *e, int id, const char *msg);

#endif
