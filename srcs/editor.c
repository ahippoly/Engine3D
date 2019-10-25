/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:03:16 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/25 11:46:00 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_hor(t_env *e)
{
	int		i;

	i = 32;
	while (i < H_IMG - 32)
	{
		e->y1 = i;
		e->x1 = 32;
		e->y2 = i;
		e->x2 = W_IMG - 64;
		while (e->x1 < e->x2)
		{	
			fill_pixel(e->sdl.pixels, e->x1, e->y1, WHITE);
			e->x1++;
		}
		i += 32;
	}
}

void	draw_ver(t_env *e)
{
	int		i;

	i = 32;
	while (i < W_IMG - 32)
	{
		e->x1 = i;
		e->y1 = 32;
		e->x2 = i;
		e->y2 = H_IMG - 55;
		while (e->y1 < e->y2)
		{
			fill_pixel(e->sdl.pixels, e->x1, e->y1, WHITE);
			e->y1++;
		}
		i += 32;
	}
	draw_hor(e);
}

void	editor(t_env *e)
{
	if (e->set_map == 0)
	{
		draw_ver(e);
		e->set_map = 1;
		print(e);
	}
	if (e->sdl.event.type == SDL_MOUSEBUTTONDOWN)
	{	
		if (e->sdl.event.button.button == SDL_BUTTON_LEFT)
		{
			if (e->select == 1)
				select_mode(e);
			else
				draw_wall(e);
		}
		if (e->sdl.event.button.button == SDL_BUTTON_RIGHT)
		{	
			e->set_wall = 0;
			clear(e);
			draw_ver(e);
			edit_draw(e);
			print(e);
		}
	}
}