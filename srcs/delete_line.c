/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:48:27 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/24 11:28:00 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	redraw(t_env *e)
{
	SDL_RenderClear(e->sdl.renderer);
	clear(e);
	draw_ver(e);
	edit_draw(e);
	SDL_UpdateTexture(e->sdl.texture, NULL, e->sdl.pixels, W_IMG * 4);
	if (SDL_RenderCopy(e->sdl.renderer, e->sdl.texture, &e->map, NULL) != 0)
		error_sdl(e);
	SDL_RenderPresent(e->sdl.renderer);
}

void	delete_line(t_env *e)
{
	int		i;
	int		j;
	char	**new;
	char	**tmp;

	i = 0;
	j = 0;
	if (!(new = (char**)malloc(sizeof(*new) * e->i_file)))
		error(e);
	while (i < e->i_file)
	{
		if (i == e->line)
		{
			free(e->file[i]);
			i++;
		}
		new[j] = e->file[i];
		i++;
		j++;
	}
	new[j] = 0;
	tmp = e->file;
	i = 0;
	e->i_file--;
	e->file = new;
	while (i < e->i_file)
	{
		e->file[i] = new[i];
		i++;
	}
	free(tmp);
	redraw(e);
}