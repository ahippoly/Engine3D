/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_edit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:13:26 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/21 14:44:12 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include <unistd.h>

void	error_edit(t_env *e, char *tmp, char *tmp2)
{
	int		i;

	i = 0;
	if (tmp != NULL)
		free(tmp);
	if (tmp2 != NULL)
		free(tmp2);
	while (i < e->i_file)
	{
		if (e->file[i] && e->file[i] != NULL)
			free(e->file[i]);
		i++;
	}
	free(e->file);
	close(e->fd);
	ft_putstr("error editor");
	if (e->sdl.window != NULL)
		SDL_DestroyWindow(e->sdl.window);
	if (e->sdl.renderer != NULL)
		SDL_DestroyRenderer(e->sdl.renderer);
	SDL_Quit();
	exit(0);
}

void	take_cord(t_env *e, int i)
{
	e->i_back = 0;
	back_pass(e, i);
	e->p3.x = ft_atoi(&e->file[i][e->i_back]) + 32;
	back_pass(e, i);
	e->p3.y = ft_atoi(&e->file[i][e->i_back]) + 32;
	back_pass(e, i);
	e->p4.x = ft_atoi(&e->file[i][e->i_back]) + 32;
	back_pass(e, i);
	e->p4.y = ft_atoi(&e->file[i][e->i_back]) + 32;
	e->p1.x = e->x1;
	e->p1.y = e->y1;
	e->p2.x = e->x2;
	e->p2.y = e->y2;
}
/*
int		check_redraw(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->i_file)
	{
		take_cord(e, i);
		if ((e->p3.x == e->x1 && e->p3.y == e->y1 && e->p4.x == e->x2 && e->p4.y == e->y2)
				|| (e->p3.x == e->x2 && e->p3.y == e->y2 && e->p4.x == e->x1 && e->p4.y == e->y1))
			return (1);
		i++;
	}
	return (0);
}
*/
SDL_Point segment_intersect(t_env *e)
{
	double a1;
	double a2;
	double b1;
	double b2;
	SDL_Point inter;

	if (e->p2.x - e->p1.x != 0 && e->p4.x - e->p3.x != 0)
	{
		a1 = (double)(e->p2.y - e->p1.y) / (e->p2.x - e->p1.x);
		b1 = e->p1.y - (double)e->p1.x * a1;
		a2 = (double)(e->p4.y - e->p3.y) / (e->p4.x - e->p3.x);
		b2 = e->p3.y - (double)e->p3.x * a2;
		inter.x = (double)(b2 - b1) / (a1  - a2);
		if (inter.x >= ft_max(e->p1.x, e->p2.x) || inter.x <= ft_min(e->p1.x, e->p2.x))
		{
			inter.x = - 42;
			inter.y = - 42;
		}
		else
			inter.y = a1 * inter.x + b1;
	}
	else if (e->p4.x - e->p3.x != 0)
	{
		a2 = (double)(e->p4.y - e->p3.y) / (e->p4.x - e->p3.x);
		b2 = e->p3.y - (double)e->p3.x * a2;
		inter.x = e->p1.x;
		inter.y = a2 * inter.x + b2;
		if (inter.y > ft_max(e->p2.y, e->p1.y) || inter.y < ft_min(e->p2.y, e->p1.y))
		{
			inter.x = - 42;
			inter.y = - 42;
		}
	}
	else if (e->p2.x - e->p1.x != 0)
	{
		a1 = (double)(e->p2.y - e->p1.y) / (e->p2.x - e->p1.x);
		b1 = e->p1.y - (double)e->p1.x * a1;
		inter.x = e->p3.x;
		inter.y = a1 * inter.x + b1;
		if (inter.y > ft_max(e->p4.y, e->p3.y) || inter.y < ft_min(e->p4.y, e->p3.y))
		{
			inter.x = - 42;
			inter.y = - 42;
		}
	}
	else
	{
		inter.x = - 42;
		inter.y = - 42;
	}
	return (inter);
}

int		check_inter(t_env *e, SDL_Point inter)
{
	if (e->p3.x == e->p4.x && ((e->p3.x < e->p1.x && e->p3.x < e->p2.x) || (e->p3.x > e->p1.x && e->p3.x > e->p2.x)))
		return (0);
	if (inter.y == e->p3.y && ((e->p1.x < e->p3.x && e->p2.x < e->p3.x && e->p1.x < e->p4.x && e->p2.x < e->p4.x) || (e->p1.x > e->p3.x && e->p2.x > e->p3.x && e->p1.x > e->p4.x && e->p2.x > e->p4.x)))
		return (0);
	if ((inter.x == e->p3.x && inter.y == e->p3.y) || (inter.x == e->p4.x && inter.y == e->p4.y))
		return(0);
	if (inter.x == e->p3.x && e->p3.x == e->p4.x && (e->p1.x == e->p3.x || e->p2.x == e->p3.x))
		return (0);
	if (inter.y == e->p3.y && e->p3.y == e->p4.y && (e->p1.y == e->p3.y || e->p2.y == e->p3.y))
		return (0);
	if (e->p3.y == e->p4.y && ((e->p3.x < inter.x && e->p4.x < inter.x) || (e->p3.x > inter.x && e->p4.x > inter.x)))
		return (0);
	if (((inter.x > e->p3.x && inter.x < e->p4.x) || (inter.x < e->p3.x && inter.x > e->p4.x))
			&& ((inter.y > e->p3.y && inter.y < e->p4.y) || (inter.y < e->p3.y && inter.y > e->p4.y)))
		return (1);
	if ((inter.x == e->p3.x && inter.y != e->p3.y) || (inter.x != e->p3.x && inter.y == e->p3.y)
			|| (inter.x == e->p4.x && inter.y != e->p4.y) || (inter.x != e->p4.x && inter.y == e->p4.y))
		return (1);
	if (inter.x == e->p3.x && e->p3.x == e->p4.x && ((inter.y > e->p3.y && inter.y < e->p4.y) || (inter.y < e->p3.y && inter.y > e->p4.y)))
		return (1);
	if (inter.y == e->p3.y && e->p3.y == e->p4.y && ((inter.x > e->p3.x || e->p4.x < inter.x)))
		return (1);
	if (inter.y + 1 == e->p3.y && e->p3.y == e->p4.y && ((inter.x > e->p3.x || e->p4.x < inter.x)))
		return (1);
	if (inter.y - 2 == e->p3.y && e->p3.y == e->p4.y && ((inter.x > e->p3.x || e->p4.x < inter.x)))
		return (1);
	return (0);
}

int	check_crossing(t_env *e)
{
	int		i;
	SDL_Point inter;

	i = 0;
	while (i < e->i_file)
	{
		take_cord(e, i);
		if ((e->p3.x == e->x1 && e->p3.y == e->y1 && e->p4.x == e->x2 && e->p4.y == e->y2)
				|| (e->p3.x == e->x2 && e->p3.y == e->y2 && e->p4.x == e->x1 && e->p4.y == e->y1))
			return (1);
		inter = segment_intersect(e);
		if ((inter.x != -42 && inter.y != -42) && check_inter(e, inter) == 1)
			return (1);
		i++;
	}
	
	return (0);
}
