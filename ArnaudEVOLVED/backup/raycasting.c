/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 05:02:25 by ahippoly          #+#    #+#             */
/*   Updated: 2019/04/04 22:14:15 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void load_corner(t_var *v, int i, int j)
{
	SDL_Point pos;
	SDL_Point size;
	SDL_Point win_size;
	t_pos diff;
	t_pos diff2;
	double width;
//	double width2;
	double depth;
	double start;
	SDL_Point pos2;
	SDL_Point size2;
	double diffx_distance;
	double diffy_screenpos;
	SDL_Point endray;
    SDL_Point startray;
    SDL_Point perso_pos;


	size.x = 3;
	size.y = 3;
	pos2.x = 0;
	pos2.y = 0;
	size2.x = 2;
	size2.y = 90;

	diff.x = i - v->perso_pos.x;
	diff.y = j - v->perso_pos.y;
	depth = (diff.x * sin((v->rot) * M_PI_2) + diff.y * cos((v->rot) * M_PI_2));
	diffx_distance = depth * cos(v->fov * M_PI_2);
	diffy_screenpos = (diff.y * sin((v->rot) * M_PI_2)) - (diff.x * cos((v->rot) * M_PI_2));
	pos.x = i * MINI_MAP_W / (v->map_size.x) +  MINI_MAP_X;
	pos.y = j * MINI_MAP_H / (v->map_size.y) +  MINI_MAP_Y;
//	width2 = diffx_distance * 2;
	width = depth * sin(v->fov * M_PI_2) * 2;
	start = diffy_screenpos + diffx_distance;
	printf("posx = %i , posy = %i\n",pos.x, pos.y);
	printf("diffx = %f, diffy = %f\n",diff.x, diff.y);
	printf("diffx_distance = %f\n", diffx_distance);
	printf("diffy_screenpos = %f\n", diffy_screenpos);
//              printf("diff_layer calc = %f\n",  sin( M_PI_2));
	printf("i = %i, j = %i\n",i , j);
	printf("start = %f, width = %f\n", start, width);
//	printf("dist2 = %f, width2 = %f\n", diffx_distance * cos(v->fov * M_PI_2), width2);
//	printf("start = %f\n", diffx_distance);
/*	endray.x =  pos.x + 100 * cos((v->rot) * M_PI_2);
	endray.y =  pos.y + 100 * -sin((v->rot) * M_PI_2);
	startray.x =  pos.x + 100 * -cos((v->rot) * M_PI_2);
	startray.y =  pos.y + 100 * sin((v->rot) * M_PI_2);
	octant(startray, endray, v->p_tab, 0xff00aa00);*/

	{
		if (start > 0 && start < width )
		{
			pos2.x = start * WIN_SIZE / width;
			//pos2.y = WIN_SIZE / 2 - 200 / (diffx_distance * 0.5);
			//size2.y = 300 / (diffx_distance * 0.5);
			pos2.y = WIN_SIZE / 2 - 200 / (depth * (v->z_pos + 0.25));
			size2.y = (WIN_SIZE / 2) / (depth * 0.5);
			put_rect(v->p_tab, pos2, size2, 0xffffffff, v->win_size);
			put_rect(v->p_tab, pos, size, 0xffffffff, v->win_size);
		}
	}         
}

void load_wall(t_var *v)
{
	int i;
	int j;

	i = 0;
	while (i < v->map_size.x)
	{
		j = 0;
		while (j < v->map_size.y)
		{
			//printf("i = %i , j = %i\n",i,j);
			if (v->map[j][i] > 0)
			{
				load_corner(v , i , j);
				load_corner(v , i+1 , j);
				load_corner(v , i , j+1);
				load_corner(v , i+1 , j+1);
			}
			j++;
		}
		i++;
	}
}
