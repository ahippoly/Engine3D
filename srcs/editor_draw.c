/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:52:02 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/23 16:12:50 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include <unistd.h>
#include <fcntl.h>

static void		check_error(t_env *e, char *tmp, char *tmp2)
{
	if (tmp == NULL || tmp2 == NULL)
		error_edit(e, tmp, tmp2);
}

static void		write_tab(t_env *e)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_itoa(e->edit_id);
	tmp = ft_itoa(e->x1 - 32);
	check_error(e, tmp, tmp2);
	if (!(e->file[e->i_file] = ft_strjoin(tmp2, "	")))
		error_edit(e, tmp, tmp2);
	free(tmp2);
	tmp2 = e->file[e->i_file];
	if (!(e->file[e->i_file] = ft_strjoin(e->file[e->i_file], tmp)))
		error_edit(e, tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = e->file[e->i_file];
	if (!(e->file[e->i_file] = ft_strjoin(e->file[e->i_file], "\t")))
		error_edit(e, tmp, tmp2);
	free(tmp);
	tmp = e->file[e->i_file];
	tmp2 = ft_itoa(e->y1 - 32);
	check_error(e, tmp, tmp2);
	if (!(e->file[e->i_file] = ft_strjoin(e->file[e->i_file], tmp2)))
		error_edit(e, tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = e->file[e->i_file];
	if (!(e->file[e->i_file] = ft_strjoin(e->file[e->i_file], "\t")))
		error_edit(e, tmp, tmp2);
	free(tmp);
	tmp2 = ft_itoa(e->x2 - 32);
	tmp = e->file[e->i_file];
	check_error(e, tmp, tmp2);
	if (!(e->file[e->i_file] = ft_strjoin(e->file[e->i_file], tmp2)))
		error_edit(e, tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = e->file[e->i_file];
	if (!(e->file[e->i_file] = ft_strjoin(e->file[e->i_file], "\t")))
		error_edit(e, tmp, tmp2);
	free(tmp);
	tmp = e->file[e->i_file];
	tmp2 = ft_itoa(e->y2 - 32);
	check_error(e, tmp, tmp2);
	if (!(e->file[e->i_file] = ft_strjoin(e->file[e->i_file], tmp2)))
		error_edit(e, tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = e->file[e->i_file];
	if (!(e->file[e->i_file] = ft_strjoin(e->file[e->i_file], "\n")))
		error_edit(e, tmp, tmp2);
	free(tmp);
	e->i_file++;
}

void			edit_draw(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->i_file)
	{
		e->i_back = 0;
		ft_putstr("oui\n");
		ft_putstr(e->file[i]);
		e->edit_id = ft_atoi(e->file[i]);
		back_pass(e, i);
		e->x1 = ft_atoi(&e->file[i][e->i_back]);
		back_pass(e, i);
		e->y1 = ft_atoi(&e->file[i][e->i_back]);
		back_pass(e, i);
		e->x2 = ft_atoi(&e->file[i][e->i_back]);
		back_pass(e, i);
		e->y2 = ft_atoi(&e->file[i][e->i_back]);
		e->x1 += 32;
		e->y1 += 32;
		e->x2 += 32;
		e->y2 += 32;
		ft_bresenham(e);
		i++;
	}
		
}

void			draw_wall(t_env *e)
{
	int		x;
	int		y;

	x = e->sdl.event.button.x + e->map.x;
	y = e->sdl.event.button.y + e->map.y;
	if (x % 32 < 16)
		x = (x / 32) * 32;
	else
		x = (x / 32) * 32 + 32;
	if (y % 32 < 16)
		y = (y / 32) * 32;
	else
		y = (y / 32) * 32 + 32;
	if (e->set_wall == 0)
	{
		e->x1 = x;
		e->y1 = y;
		e->set_wall = 1;
	}
	else if (e->x1 == x && e->y1 == y)
		return ;
	else
	{
		e->x2 = x;
		e->y2 = y;
		//e->set_wall = 0;
		if (e->x1 > 31 && e->x1 < 1857 && e->y1 > 31 && e->y1 < 1029
			&& e->x2 > 31 && e->x2 < 1857 && e->y2 > 31 && e->y2 < 1029)
		{
			if (/*check_redraw(e) == 1 ||*/ (e->i_file >= 1 && check_crossing(e) == 1))
				return ;
			write_tab(e);
			ft_bresenham(e);
		}
		SDL_RenderClear(e->sdl.renderer);
		SDL_UpdateTexture(e->sdl.texture, NULL, e->sdl.pixels, W_IMG * 4);
		if (SDL_RenderCopy(e->sdl.renderer, e->sdl.texture, &e->map, NULL) != 0)
			error_sdl(e);
		SDL_RenderPresent(e->sdl.renderer);
	}
}