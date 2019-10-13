/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:02:22 by ahippoly          #+#    #+#             */
/*   Updated: 2019/10/13 20:35:11 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	oct_ini(t_oct *oct, SDL_Point pos1, SDL_Point pos2, int pos[2][2])
{
	pos[0][0] = pos1.x;
	pos[0][1] = pos2.x;
	pos[1][0] = pos1.y;
	pos[1][1] = pos2.y;
	oct->inc[0] = pos2.x - pos1.x > 0 ? 1 : -1;
	oct->inc[1] = pos2.y - pos1.y > 0 ? 1 : -1;
	oct->d[0] = (pos2.x - pos1.x) * 2 * oct->inc[0];
	oct->d[1] = (pos2.y - pos1.y) * 2 * oct->inc[1];
	oct->bool = oct->d[0] > oct->d[1] ? 1 : 0;
	oct->boolxy = 1 - oct->bool;
	oct->e = oct->d[oct->boolxy] / 2;
	oct->ecart = (pos[oct->boolxy][1] - pos[oct->boolxy][0])
		* oct->inc[oct->boolxy];
}

void calc_new_point(int *v1, int *v2, int *v3, int *v4)
{
	
}

void adapt_out_screen(SDL_Point *pp1, SDL_Point *pp2)
{
	SDL_Point p1;
	SDL_Point p2;
	int adapt;

	p1 = *pp1;
	p2 = *pp2;
	adapt = 0;
	//printf("pre = p1, x = %d y = %d, p2 x = %d y = %d\n",p1.x, p1.y, p2.x, p2.y);
	if (!(p1.x > WIN_SIZE && p2.x > WIN_SIZE) 
		&& !(p1.x <= 0 && p2.x <= 0) 
		&& !(p1.y > WIN_SIZE && p2.y > WIN_SIZE) 
		&& !(p1.y <= 0 && p2.y <= 0))
	{
//		printf("beg = p1, x = %d y = %d, p2 x = %d y = %d\n",p1.x, p1.y, p2.x, p2.y);
		//printf("abs x = %d, abs y = %d\n",ft_abs(p1.x - p2.x), ft_abs(p1.y - p2.y));
		if (p1.x > WIN_SIZE)
		{
			adapt = 1;
			p1.y = p2.y + (WIN_SIZE - p2.x) * (p1.y - p2.y) / (p1.x - p2.x);
			p1.x = WIN_SIZE;
		}
		if (p2.x > WIN_SIZE)
		{
			adapt = 2;
			p2.y = p1.y + (WIN_SIZE - p1.x) * (p2.y - p1.y) / (p2.x - p1.x);
			p2.x = WIN_SIZE;
		}
		if (p1.y > WIN_SIZE)
		{
			adapt = 3;
			p1.x = p1.x + (WIN_SIZE - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
			p1.y = WIN_SIZE;
		}
		if (p2.y > WIN_SIZE)
		{
			adapt = 4;
			p2.x = p2.x + (WIN_SIZE - p2.y) * (p1.x - p2.x) / (p1.y - p2.y);
			p2.y = WIN_SIZE;
		}
		if (p1.x < 0)
		{
			adapt = 5;
			p1.y = p1.y + -p1.x * (p2.y - p1.y) / (p2.x - p1.x);
			p1.x = 0;
		}
		if (p2.x < 0)
		{
			adapt = 6;
			p2.y = p2.y + -p2.x * (p1.y - p2.y) / (p1.x - p2.x);
			p2.x = 0;
		}
		if (p1.y < 0)
		{
			adapt = 7;
			p1.x = p1.x + -p1.y * (p2.x - p1.x) / (p2.y - p1.y);
			p1.y = 0;
		}
		if (p2.y < 0)
		{
			adapt = 8;
			p2.x = p2.x + -p2.y * (p1.x - p2.x) / (p1.y - p2.y);
			p2.y = 0;
		}
		*pp1 = p1;
		*pp2 = p2;
		if (adapt > 0)
			printf("res = p1, x = %d y = %d, p2 x = %d y = %d, adapt = %d\n",p1.x, p1.y, p2.x, p2.y,adapt);
	}
}

void	octant(SDL_Point pos1, SDL_Point pos2, char *pixel, int color)
{
	t_oct			oct;
	int				pos[2][2];
	int				i;
	unsigned int	*p_tab;
	int 			length;

	if (pos1.x != -42 && pos2.x != -42)
	{
		p_tab = (unsigned int*)pixel;
		i = 0;
		adapt_out_screen(&pos1, &pos2);
		oct_ini(&oct, pos1, pos2, pos);
		length = ft_min(WIN_SIZE, ft_abs(pos[oct.boolxy][0] - pos[oct.boolxy][1]));
		//printf("pixels drawed = %i\n", length);
		while (i < length)
		{
			if (pos[0][0] < WIN_SIZE && pos[0][0] > 0 && pos[1][0] > 0
				&& pos[1][0] < WIN_SIZE)
				p_tab[pos[0][0] + pos[1][0] * WIN_SIZE] = color;
			if ((oct.e -= oct.d[oct.bool]) <= 0)
			{
				pos[oct.bool][0] += oct.inc[oct.bool];
				oct.e += oct.d[oct.boolxy];
			}
			i++;
			pos[oct.boolxy][0] += oct.inc[oct.boolxy];
		}
	}
}

SDL_Point	*mem_octant(SDL_Point pos1, SDL_Point pos2, int *length)
{
	t_oct			oct;
	int				pos[2][2];
	int				i;
	SDL_Point		*pos_tab;

	*length = 0;
	pos_tab = NULL;
	if (pos1.x != -42 && pos2.x != -42)
	{
		i = 0;
		oct_ini(&oct, pos1, pos2, pos);
		*length = ft_min(WIN_SIZE * 4, ft_abs(pos[oct.boolxy][0] - pos[oct.boolxy][1]));
		//printf("mem_octant, pixels drawed = %i\n", *length);
		//printf("pos1 = %i, pos2 = %i\n",pos[oct.boolxy][0], pos[oct.boolxy][1]);
		pos_tab = (SDL_Point*)malloc(sizeof(SDL_Point) * *length);
		while (i < *length)
		{
			pos_tab[i].x = pos[0][0];
			pos_tab[i].y = pos[1][0];
			if ((oct.e -= oct.d[oct.bool]) <= 0)
			{
				pos[oct.bool][0] += oct.inc[oct.bool];
				oct.e += oct.d[oct.boolxy];
			}
			i++;
			pos[oct.boolxy][0] += oct.inc[oct.boolxy];
		}
	}
	return (pos_tab);
}

void	fill_rectangle(t_line top, t_line bot, char *pixel, int color)
{
	t_oct			oct[2];
	int				pos[2][2][2];
	double 			dist[2];
	unsigned int	*p_tab;
	int 			longer;

	p_tab = (unsigned int*)pixel;
	oct_ini(&oct[0], top.pos1, top.pos2, pos[0]);
	oct_ini(&oct[1], bot.pos1, bot.pos2, pos[1]);
	dist[0] = hypot(top.pos2.x - top.pos1.x, top.pos2.y - top.pos1.y);
	dist[1] = hypot(bot.pos2.x - bot.pos1.x, bot.pos2.y - bot.pos1.y);
	longer = dist[1] > dist[0] ? 1 : 0;

	while (pos[longer][oct[longer].boolxy][0] != pos[longer][oct[longer].boolxy][1])
	{
		if (pos[longer][0][0] < WIN_SIZE && pos[longer][0][0] > 0 && pos[longer][1][0] > 0
			&& pos[longer][1][0] < WIN_SIZE)
			p_tab[pos[longer][0][0] + pos[longer][1][0] * WIN_SIZE] = color;
		if ((oct[longer].e -= oct[longer].d[oct[longer].bool]) <= 0)
		{
			pos[longer][oct[longer].bool][0] += oct[longer].inc[oct[longer].bool];
			oct[longer].e += oct[longer].d[oct[longer].boolxy];
		}
		pos[longer][oct[longer].boolxy][0] += oct[longer].inc[oct[longer].boolxy];
	}
}

void disp_text(char *pixels, char *img_tab, SDL_Point size)
{
	unsigned int *screen;
	unsigned int *img;
	int i;
	int j;


	screen = (unsigned int*)pixels;
	img = (unsigned int*)img_tab;
	j = 0;
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			screen[i + j * WIN_SIZE] = img[i + j * size.x];
			i++;
		}
		j++;
	}
}

void    bresenham_texture(t_line line, char *pixels, t_text *text, double x_ratio)
{
	t_oct           oct;
    int             pos[2][2];
    float           i;
	float			step;
    unsigned int    *p_tab;
	unsigned int	*text_pix;
	int				text_x_ratio;

    if (line.pos1.x != -10000 && line.pos2.x != -10000)
    {
		p_tab = (unsigned int*)pixels;
		text_pix = (unsigned int*)text->pixels;
        i = 0;
        oct_ini(&oct, line.pos1, line.pos2, pos);
		step = (double)text->w / ft_abs(pos[oct.boolxy][1] - pos[oct.boolxy][0]);
		text_x_ratio = (int)(x_ratio * text->w);
//		printf("x_ratio = %i\n",text_x_ratio);
        while (pos[oct.boolxy][0] != pos[oct.boolxy][1])
        {
            if (pos[0][0] < WIN_SIZE && pos[0][0] > 0 && pos[1][0] > 0
                && pos[1][0] < WIN_SIZE)
			{
                p_tab[pos[0][0] + pos[1][0] * WIN_SIZE] = text_pix[text_x_ratio + ((int)i * text->w)];
//                p_tab[pos[0][0] + pos[1][0] * WIN_SIZE] = text_pix[512*512 - 1];
//                p_tab[pos[0][0] + pos[1][0] * WIN_SIZE] = text_pix[(int)(size.x * x_ratio)];
//                p_tab[pos[0][0] + pos[1][0] * WIN_SIZE] = 0xff000000 | (int)(x_ratio * 256);
//                p_tab[pos[0][0] + pos[1][0] * WIN_SIZE] = 0xff000000 | ((int)(i * 65536) & 0xff00ff00) | (int)(x_ratio * 256);
//				printf("current y ratio = %i\n",(int)(i));
			}
			if ((oct.e -= oct.d[oct.bool]) <= 0)
            {
                pos[oct.bool][0] += oct.inc[oct.bool];
                oct.e += oct.d[oct.boolxy];
            }
            i += step;
            pos[oct.boolxy][0] += oct.inc[oct.boolxy];
        }
    }
//	printf("i = %f \n", i);
}
