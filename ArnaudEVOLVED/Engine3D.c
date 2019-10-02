/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 01:19:12 by ahippoly          #+#    #+#             */
/*   Updated: 2019/09/26 05:07:41 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

SDL_Point	vox_on_screen(t_vox point, t_vox cam_pos, t_pos cam_rot)
{
	t_vox		diff;
	double		depth;
	SDL_Point	screen_pos;
	t_pos		sin_rot;
	t_pos		cos_rot;

	sin_rot.x = sin(cam_rot.x * M_PI_2);
	sin_rot.y = sin(cam_rot.y * M_PI_2);
	cos_rot.x = cos(cam_rot.x * M_PI_2);
	cos_rot.y = cos(cam_rot.y * M_PI_2);

	diff.x = point.x - cam_pos.x;
	diff.y = point.y - cam_pos.y;
	diff.z = point.z - cam_pos.z;

	depth = diff.x * sin_rot.y * sin_rot.x + diff.y * cos_rot.y * sin_rot.x + diff.z * cos_rot.x;
	screen_pos.x = (diff.y * sin_rot.y - diff.x * cos_rot.y + depth) * WIN_SIZE / (depth * 2);
	screen_pos.y = (diff.z * sin_rot.x - diff.x * cos_rot.x * sin_rot.y - diff.y * cos_rot.x * cos_rot.y + depth) * WIN_SIZE / (depth * 2);

	printf("vox_on_screen depth = %f\n", depth);
	if (depth < 0)
		screen_pos.x = -42;
	return (screen_pos);
}

t_line create_line(int x1, int y1, int x2, int y2)
{
	t_line line;

	line.pos1.x = x1;
	line.pos1.y = y1;
	line.pos2.x = x2;
	line.pos2.y = y2;
	return (line);
}

t_line create_line_sdl(SDL_Point pos1, SDL_Point pos2)
{
	t_line line;

	line.pos1.x = pos1.x;
	line.pos1.y = pos1.y;
	line.pos2.x = pos2.x;
	line.pos2.y = pos2.y;
	return (line);
}

void draw_texture(t_line top, t_line bot, char *pixels, t_text *text)
{
	int i;
	double j;
	double step;
	double step_text;
	int length[2];
	SDL_Point *line[2];
	int longer;

	line[0] = mem_octant(top.pos1, top.pos2, &length[0]);
	line[1] = mem_octant(bot.pos1, bot.pos2, &length[1]);
	if (length[0] != 0 && length[1] != 0)
	{
		if (length[0] > length[1])
		{
			step = (double)length[1] / length[0];
			step_text = text->w / length[0];
			longer = 0;
		}
		else
		{
			longer = 1;
			step = (double)length[0] / length[1];
			step_text = text->w / length[1];
		}
		i = 0;
		j = 0;
		while (i < length[longer])
		{
			bresenham_texture(create_line_sdl(line[longer][i], line[1 - longer][(int)j]), pixels, text, (double)i / length[longer]);
			j += step;
			i++;
		}
	}
	free(line[0]);
	free(line[1]);
}
