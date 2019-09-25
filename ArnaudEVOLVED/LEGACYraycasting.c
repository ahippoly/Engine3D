/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 05:02:25 by ahippoly          #+#    #+#             */
/*   Updated: 2019/04/04 17:23:21 by ahippoly         ###   ########.fr       */
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
	float distance;
//	double coef_y;
//	double coef_y2;
	double width;
	double start;
	SDL_Point pos2;
	SDL_Point size2;
//	double diffx_coef_y;
//	double diffx_coef_y2;
	double diffx_distance;
	double diffy_screenpos;
	SDL_Point endray;
    SDL_Point startray;
    SDL_Point perso_pos;


	size.x = 3;
	size.y = 3;
//	coef_y = 0;
//	coef_y2 = 0;
	pos2.x = 0;
	pos2.y = 0;
	size2.x = 2;
	size2.y = 90;
//	diffx_coef_y = 0;
//	diffx_coef_y2 = 0;

	diff.x = i - v->perso_pos.x;
	diff.y = j - v->perso_pos.y;
	diff2.x = diff.x * diff.x;
	diff2.y = diff.y * diff.y;
	diffx_distance = (diff.x * sin((v->rot + 0.5) * M_PI_2)) + (diff.y * cos((v->rot + 0.5) * M_PI_2));
	diffy_screenpos = (diff.y * sin((v->rot + 0.5) * M_PI_2)) - (diff.x * cos((v->rot + 0.5) * M_PI_2));
	pos.x = i * MINI_MAP_W / (v->map_size.x) +  MINI_MAP_X;
	pos.y = j * MINI_MAP_H / (v->map_size.y) +  MINI_MAP_Y;
	distance = diff2.x + diff2.y;
/*	if (v->rot != 0) 
		coef_y = (1 / v->rot) - 1;
	else
		coef_y = 2147483647;                     legacy bloc
	if (v->rot != 1)
		coef_y2 = (1 / (1 - v->rot)) - 1;
	else
	coef_y2 = 2147483647;
	diffx_coef_y = diff.x * coef_y;
	diffx_coef_y2 = diff.x * -coef_y2;
	start = diffx_coef_y + diff.y;*/
	width = diffx_distance * 2;
/*	printf("posx = %i , posy = %i\n",pos.x, pos.y);
	printf("diffx = %f, diffy = %f\n",diff.x, diff.y);
	printf("coef y = %f\n", coef_y);
	printf("coef y2 = %f\n", coef_y2);
	printf("coefdiff 1 = %f ,coefdif 2 = %f\n", diffx_coef_y, diffx_coef_y2);
	printf("diffx_distance = %f\n", diffx_distance);
	printf("diffy_screenpos = %f\n", diffy_screenpos);
//              printf("diff_layer calc = %f\n",  sin( M_PI_2));
	printf("i = %i, j = %i\n",i , j);
	printf("start = %f, width = %f\n", start, width);*/
//	octant(startray, endray, v->p_tab, 0x0000aa00);
	start = diffy_screenpos + diffx_distance;
//	if (v->rot >= 0 && v->rot < 2)
	{
		//if (diff.x > 0 && diffx_coef_y > diff.y && diffx_coef_y2 < diff.y )
		if (start > 0 && start < width )
		{
			pos2.x = start * WIN_SIZE / width;
			pos2.y = WIN_SIZE / 2 - 200 / (diffx_distance * 0.5);
			size2.y = 300 / (diffx_distance * 0.5);
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
	//printf("test\n");
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
