/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:38:48 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/28 15:51:41 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	find_select(t_env *e, int i)
{
	if (e->select_line == 1)
	{
		clear(e);
		draw_ver(e);
		edit_draw(e);
	}
	e->sec[e->secteur].line = i;
	e->x1 = e->p3.x;
	e->y1 = e->p3.y;
	e->x2 = e->p4.x;
	e->y2 = e->p4.y;
	e->tmp_id = e->edit_id;
	e->edit_id = -1;
	e->select_line = 1;
	ft_bresenham(e);
	print(e);
}

void	select_mode(t_env *e)
{
	int			x;
	int			y;
	int			i;
	SDL_Point	inter;

	i = 0;
	x = e->sdl.event.button.x + e->map.x;
	y = e->sdl.event.button.y + e->map.y;
	e->x1 = x + 5;
	e->x2 = x - 5;
	e->y1 = y + 5;
	e->y2 = y - 5;
	e->i_back = 0;
	ft_putstr(e->sec[e->secteur].file);
	ft_putchar('\n');
	ft_putnbr(e->i_back);
	ft_putchar('\n');
	while (i < e->sec[e->secteur].i_file)
	{
		take_cord(e, i);
		inter = segment_intersect(e);
		if ((inter.x == -42 && inter.y == -42) || check_inter(e, inter) == 0)
		{
			e->p1.x = x - 5;
			e->p2.x = x + 5;
			e->p1.y = y + 5;
			e->p2.y = y - 5;
			inter = segment_intersect(e);
			if ((inter.x == -42 && inter.y == -42) || check_inter(e, inter) == 0)
			{
				e->x1 = x + 5;
				e->x2 = x - 5;
				e->y1 = y + 5;
				e->y2 = y - 5;
			}			
			else
			{
				find_select(e, i);
				return ;
			}

		}
		else
		{
			find_select(e, i);
			return ;
		}				
		i++;
	}
}