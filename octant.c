/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:02:22 by ahippoly          #+#    #+#             */
/*   Updated: 2019/09/17 20:58:35 by ahippoly         ###   ########.fr       */
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
	oct->e = oct->d[1 - oct->bool] / 2;
	oct->ecart = (pos[1 - oct->bool][1] - pos[1 - oct->bool][0])
		* oct->inc[1 - oct->bool];
}

void	octant(SDL_Point pos1, SDL_Point pos2, char *pixel, int color)
{
	t_oct			oct;
	int				pos[2][2];
	float			i;
	int				boolxy;
	unsigned int	*p_tab;

	if (pos1.x != -10000 && pos2.x != -10000)
	{
		p_tab = (unsigned int*)pixel;
		i = 0;
		oct_ini(&oct, pos1, pos2, pos);
		boolxy = 1 - oct.bool;
		while (pos[boolxy][0] != pos[boolxy][1])
		{
			if (pos[0][0] < WIN_SIZE && pos[0][0] > 0 && pos[1][0] > 0
				&& pos[1][0] < WIN_SIZE)
				p_tab[pos[0][0] + pos[1][0] * WIN_SIZE] = color;
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
