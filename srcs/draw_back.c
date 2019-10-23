/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:02:43 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/22 13:58:50 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	back_pass(t_env *e, int i)
{
	while (e->file[i][e->i_back] != '\t')
		e->i_back++;
	while (e->file[i][e->i_back] == '\t')
		e->i_back++;
}

void	clear(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < H_IMG)
	{
		j = 0;
		while (j < W_IMG)
		{
			fill_pixel(e->sdl.pixels, j, i, BLACK);
			j++;
		}
		i++;
	}
}


void	draw_back(t_env *e)
{
	int		i;

	e->set_wall = 0;
	i = 0;
	e->i_file--;
	SDL_RenderClear(e->sdl.renderer);
	ft_bzero(e->file[e->i_file], ft_strlen(e->file[e->i_file]));
	free(e->file[e->i_file]);
	clear(e);
	draw_ver(e);
	edit_draw(e);
	SDL_UpdateTexture(e->sdl.texture, NULL, e->sdl.pixels, W_IMG * 4);
	if (SDL_RenderCopy(e->sdl.renderer, e->sdl.texture, &e->map, NULL) != 0)
		error_sdl(e);
	SDL_RenderPresent(e->sdl.renderer);
}

void	error(t_env *e)
{
	//free all
	e->i_file++;
	exit (1);
}