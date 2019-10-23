/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_vert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:27:44 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/09 13:37:14 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_octant4(t_env *e, float f)
{
	f = e->dx;
	e->dx *= 2;
	e->dy *= 2;
	while (e->x1 > e->x2)
	{
		set_color(e);
		e->x1--;
		f += e->dy;
		if (f >= 0)
		{
			e->y1++;
			f += e->dx;
		}
	}
}

void	ft_octant3(t_env *e, float f)
{
	f = e->dy;
	e->dx *= 2;
	e->dy *= 2;
	while (e->y1 < e->y2)
	{
		set_color(e);
		e->y1++;
		f += e->dx;
		if (f <= 0)
		{
			e->x1--;
			f += e->dy;
		}
	}
}

void	ft_octant5(t_env *e, float f)
{
	f = e->dx;
	e->dx *= 2;
	e->dy *= 2;
	while (e->x1 > e->x2)
	{
		set_color(e);
		e->x1--;
		f -= e->dy;
		if (f >= 0)
		{
			e->y1--;
			f += e->dx;
		}
	}
}

void	ft_octant6(t_env *e, float f)
{
	f = e->dy;
	e->dx *= 2;
	e->dy *= 2;
	while (e->y1 > e->y2)
	{
		set_color(e);
		e->y1--;
		f -= e->dx;
		if (f >= 0)
		{
			e->x1--;
			f += e->dy;
		}
	}
}
