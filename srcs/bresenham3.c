/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:52:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/09 13:37:42 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_octant_horleft(t_env *e)
{
	while (e->x1 > e->x2)
	{
		set_color(e);
		e->x1--;
	}
}

void	ft_octant_vert(t_env *e)
{
	while (e->y1 < e->y2)
	{
		set_color(e);
		e->y1++;
	}
}

void	ft_octant_vert2(t_env *e)
{
	while (e->y1 > e->y2)
	{
		set_color(e);
		e->y1--;
	}
}

void	ft_octant_horright(t_env *e)
{
	while (e->x1 < e->x2)
	{
		set_color(e);
		e->x1++;
	}
}
