/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:02:22 by ahippoly          #+#    #+#             */
/*   Updated: 2019/09/21 19:35:59 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

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

void	octant(SDL_Point pos1, SDL_Point pos2, char *pixel, int color)
{
	t_oct			oct;
	int				pos[2][2];
	float			i;
	unsigned int	*p_tab;

	if (pos1.x != -10000 && pos2.x != -10000)
	{
		p_tab = (unsigned int*)pixel;
		i = 0;
		oct_ini(&oct, pos1, pos2, pos);
		while (pos[oct.boolxy][0] != pos[oct.boolxy][1])
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

t_memline	mem_octant(SDL_Point pos1, SDL_Point pos2)
{
	t_oct			oct;
	int				pos[2][2];
	int				i;
	t_memline		pos_tab;

	pos_tab.length = 0;
	pos_tab.pos = NULL;
	if (pos1.x != -10000 && pos2.x != -10000)
	{
		i = 0;
		pos_tab.length = ft_abs(pos[oct.boolxy][0] - pos[oct.boolxy][1]);
		pos_tab.pos = (SDL_Point*)malloc(sizeof(SDL_Point) * pos_tab.length);
		oct_ini(&oct, pos1, pos2, pos);
		while (pos[oct.boolxy][0] != pos[oct.boolxy][1])
		{
			pos_tab.pos[i].x = pos[0][0];
			pos_tab.pos[i].y = pos[1][0];
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
	int 			longer_line;

	p_tab = (unsigned int*)pixel;
	i = 0;
	oct_ini(&oct[0], top.pos1, top.pos2, pos[0]);
	oct_ini(&oct[1], bot.pos1, bot.pos2, pos[1]);
	dist[0] = hypot(top.pos2.x - top.pos.x, top.pos2.y - top.pos1.y);
	dist[1] = hypot(bot.pos2.x - bot.pos.x, bot.pos2.y - bot.pos1.y);
	longer = dist[1] > dist[0] ? 1 : 0;

	while (pos[longer][oct.boolxy][0] != pos[longer][oct.boolxy][1])
	{
		if (pos[longer][0][0] < WIN_SIZE && pos[longer][0][0] > 0 && pos[longer][1][0] > 0
			&& pos[longer][1][0] < WIN_SIZE)
			p_tab[pos[longer][0][0] + pos[longer][1][0] * WIN_SIZE] = color;
		if ((oct[longer].e -= oct[longer].d[oct.bool]) <= 0)
		{
			pos[longer][oct[longer].bool][0] += oct[longer].inc[oct[longer].bool];
			oct[longer].e += oct[longer].d[oct[longer].boolxy];
		}
		pos[longer][oct[longer].boolxy][0] += oct[longer].inc[oct[longer].boolxy];
	}
}

void    bresenham_texture(SDL_Point pos1, SDL_Point pos2, t_text *img, double x_ratio)
{
	t_oct           oct;
    int             pos[2][2];
    float           i;
    int             boolxy;
    unsigned int    *p_tab;
	unsigned int	*text_pix;

    if (pos1.x != -10000 && pos2.x != -10000)
    {
        p_tab = (unsigned int*)pixel;
		text_pix = (unsigned int*)text_pix;
        i = 0;
        oct_ini(&oct, pos1, pos2, pos);
        boolxy = 1 - oct.bool;
        while (pos[boolxy][0] != pos[boolxy][1])
        {
            if (pos[0][0] < WIN_SIZE && pos[0][0] > 0 && pos[1][0] > 0
                && pos[1][0] < WIN_SIZE)
                p_tab[pos[0][0] + pos[1][0] * WIN_SIZE] = img->pixels;
            if ((oct.e -= oct.d[oct.bool]) <= 0)
            {
                pos[oct.bool][0] += oct.inc[oct.bool];
                oct.e += oct.d[1 - oct.bool];
            }
            i++;
            pos[1 - oct.bool][0] += oct.inc[1 - oct.bool];
        }
    }
}
