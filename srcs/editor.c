/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:03:16 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/22 13:47:16 by ceaudouy         ###   ########.fr       */
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
		SDL_UpdateTexture(e->sdl.texture, NULL, e->sdl.pixels, W_IMG * 4);
		if (SDL_RenderCopy(e->sdl.renderer, e->sdl.texture, &e->map, NULL) != 0)
			error_sdl(e);
		SDL_RenderPresent(e->sdl.renderer);
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
				e->set_wall = 0;
	}
	if (e->sdl.event.type == SDL_KEYDOWN)
	{
		if (e->sdl.event.key.keysym.scancode == 42 && e->i_file > 0 && e->select == 0)
			draw_back(e);
		if (e->sdl.event.key.keysym.scancode == 42 && e->i_file > 0 && e->select == 1)
			delete_line(e);
		if (e->sdl.event.key.keysym.scancode == 20 && e->i_file > 0)
		{
			e->select ^= 1;
			if (e->select == 0)
				e->edit_id = e->tmp_id;
		}
	}
}