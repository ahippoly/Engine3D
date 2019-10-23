/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:29:59 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/21 12:39:55 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		fill_pixel(char *pixels, int x, int y, int color)
{
	int	i;

	i = (x + y * W_IMG) * 4;
	if (x >= 0 && x < W_IMG && y >= 0 && y < H_IMG)
	{
		pixels[i] = (char)(color & 0x0000ff);
		pixels[i + 1] = (char)((color & 0x00ff00) >> 8);
		pixels[i + 2] = (char)((color & 0xff0000) >> 16);
		if (color == WHITE)
			pixels[i + 3] = (char)(((color & 0xff000000) >> 16) >> 8) + 100;
		else
			pixels[i + 3] = (char)(((color & 0xff000000) >> 16) >> 8) + 255;
	}
}


void	set_color(t_env *e)
{
	if (e->edit_id == -1)
		fill_pixel(e->sdl.pixels, e->x1, e->y1, PINK);
	if (e->edit_id == 0)
		fill_pixel(e->sdl.pixels, e->x1, e->y1, RED);
	if (e->edit_id == 1)
		fill_pixel(e->sdl.pixels, e->x1, e->y1, GREEN);
	if (e->edit_id == 2)
		fill_pixel(e->sdl.pixels, e->x1, e->y1, BLUE);
	if (e->edit_id == 10)
		fill_pixel(e->sdl.pixels, e->x1, e->y1, WHITE);
}