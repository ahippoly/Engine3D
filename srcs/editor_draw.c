/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:52:02 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/29 16:11:49 by ceaudouy         ###   ########.fr       */
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

void			edit_draw(t_env *e)
{
	int		i;

	i = 0;
	e->i_back = 0;
	while (i < e->sec[e->secteur].i_file)
	{
		e->edit_id = ft_atoi(e->sec[e->secteur].file);
		back_pass(e, i);
		e->x1 = ft_atoi(&e->sec[e->secteur].file[e->i_back]);
		back_pass(e, i);
		e->y1 = ft_atoi(&e->sec[e->secteur].file[e->i_back]);
		back_pass(e, i);
		e->x2 = ft_atoi(&e->sec[e->secteur].file[e->i_back]);
		back_pass(e, i);
		e->y2 = ft_atoi(&e->sec[e->secteur].file[e->i_back]);
		e->x1 += 32;
		e->y1 += 32;
		e->x2 += 32;
		e->y2 += 32;
		ft_bresenham(e);
		i++;
	}
		
}


static void		write_tab(t_env *e)
{
	char	*tmp;
	char	*tmp2;

	tmp = e->sec[e->secteur].file;
	tmp2 = ft_itoa(e->edit_id);
	check_error(e, tmp, tmp2);
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, tmp2)))
		error_edit(e, tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp2 = e->sec[e->secteur].file;
	tmp = ft_itoa(e->x1 - 32);
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, "	")))
		error_edit(e, tmp, tmp2);
	free(tmp2);
	tmp2 = e->sec[e->secteur].file;
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, tmp)))
		error_edit(e, tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = e->sec[e->secteur].file;
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, "\t")))
		error_edit(e, tmp, tmp2);
	free(tmp);
	tmp = e->sec[e->secteur].file;
	tmp2 = ft_itoa(e->y1 - 32);
	check_error(e, tmp, tmp2);
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, tmp2)))
		error_edit(e, tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = e->sec[e->secteur].file;
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, "\t")))
		error_edit(e, tmp, tmp2);
	free(tmp);
	tmp2 = ft_itoa(e->x2 - 32);
	tmp = e->sec[e->secteur].file;
	check_error(e, tmp, tmp2);
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, tmp2)))
		error_edit(e, tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = e->sec[e->secteur].file;
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, "\t")))
		error_edit(e, tmp, tmp2);
	free(tmp);
	tmp = e->sec[e->secteur].file;
	tmp2 = ft_itoa(e->y2 - 32);
	check_error(e, tmp, tmp2);
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, tmp2)))
		error_edit(e, tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = e->sec[e->secteur].file;
	if (!(e->sec[e->secteur].file = ft_strjoin(e->sec[e->secteur].file, "\n")))
		error_edit(e, tmp, tmp2);
	free(tmp);
	e->sec[e->secteur].i_file++;
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
		draw_clic(e, x, y);
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
			if (/*check_redraw(e) == 1 ||*/ (e->sec[e->secteur].i_file >= 1 && check_crossing(e) == 1))
				return ;
			write_tab(e);
			clear(e);;;
			ft_bresenham(e);
			draw_ver(e);
			edit_draw(e);
			draw_clic(e, x, y);
		}
		print(e);
	}
}