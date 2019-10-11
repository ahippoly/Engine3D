/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 01:19:12 by ahippoly          #+#    #+#             */
/*   Updated: 2019/10/11 21:25:00 by ahippoly         ###   ########.fr       */
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

t_pos line_intersect(t_vox cam_pos, t_pos cam_rot)
{
	double sin_rot;
	double cos_rot;
	double a1;
	double a2;
	double b1;
	double b2;

	t_pos inter;

	t_vox p1;
	t_vox p2;

	p1.x = 1;
	p1.y = 0;
	p1.z = 0;

	p2.x = 1;
	p2.y = 1;
	p2.z = 0;

	sin_rot = sin(cam_rot.y * M_PI_2);
	cos_rot = cos(cam_rot.y * M_PI_2);

	if (sin_rot < 0.001 && sin_rot > -0.001)
	{
		printf("case : sin_rot = 0\n");
		a1 = (p2.y - p1.y) / (p2.x - p1.x);
		b1 = p1.y - p1.x * a1;
		inter.x = cam_pos.x;
		inter.y = a1 * inter.x + b1;
		printf("inter.x = %f, max x = %f, min x = %f\n", inter.x, ft_fmax(p2.x, p1.x), ft_fmin(p2.x, p1.x));
		if (inter.x > ft_fmax(p2.x, p1.x) || inter.x < ft_fmin(p2.x, p1.x))
		{
			inter.x = - 42;
			inter.y = - 42;
		}
	}
	else if (p2.x - p1.x != 0)
	{
		a1 = (p2.y - p1.y) / (p2.x - p1.x);
		b1 = p1.y - p1.x * a1;
		
		a2 = cos_rot / sin_rot;
		b2 = cam_pos.y - cam_pos.x * a2;
		
		inter.x = (b2 - b1) / (a1  - a2);
		printf("inter.x = %f, max x = %f, min x = %f\n", inter.x, ft_fmax(p2.x, p1.x), ft_fmin(p2.x, p1.x));
		if (inter.x > ft_fmax(p1.x, p2.x) || inter.x < ft_fmin(p1.x, p2.x))
		{
			inter.x = - 42;
			inter.y = - 42;
		}
		else
			inter.y = a1 * inter.x + b1;
	}
	else 
	{
		a2 = cos_rot / sin_rot;
		b2 = cam_pos.y - cam_pos.x * a2;
		inter.x = p1.x;
		inter.y = a2 * inter.x + b2;
		printf("inter.y = %f, max x = %f, min x = %f\n", inter.y, ft_fmax(p2.y, p1.y), ft_fmin(p2.y, p1.y));
		if (inter.y > ft_max(p2.y, p1.y) || inter.y < ft_min(p2.y, p1.y))
		{
            inter.x = - 42;
            inter.y = - 42;
        }
	}
	printf("a1 = %f, b1 = %f\na2 = %f, b2 = %f\n",a1, b1, a2, b2);
	printf("sin_rot = %f, cos_rot = %f\n", sin_rot, cos_rot);
	printf("inter.x = %f, inter.y = %f\n", inter.x, inter.y);
	return (inter);
}

//t_vox cut_frustum(t_vox cam_pos, t_pos cam_rot, t_vox p1, t_vox p2)
t_vox cut_frustum(t_vox cam_pos, t_pos cam_rot)
{
	t_pos scale;
	t_pos sin_rot;
	t_pos cos_rot;
	t_pos cam_dir;
	t_vox intersect;

	t_vox p1;
	t_vox p2;
	double divid;

	p1.x = 2;
	p1.y = 1;
	p1.z = 0;

	p2.x = 4;
	p2.y = 1;
	p2.z = 0;

	sin_rot.y = sin(cam_rot.y * M_PI_2);
	cos_rot.y = cos(cam_rot.y * M_PI_2);

	cam_dir.x = cam_pos.x + sin_rot.y * 1;
	cam_dir.y = cam_pos.y + cos_rot.y * 1;

	scale.x = ((p2.x - p1.x) * (cam_pos.y - p1.y) - (p2.y - p1.y) * (cam_pos.x - p1.x)) /
		((p2.y - p1.y) * (cam_dir.x - cam_pos.x) - (p2.x - p1.x) * (cam_dir.y - cam_pos.y));
	scale.y = ((cam_dir.x - cam_pos.x) * (cam_pos.y - p1.y) - (cam_dir.y - cam_pos.y) * (cam_pos.x * p1.x)) /
		((p2.y - p1.y) * (cam_dir.x - cam_pos.x) - (p2.x - p1.x) * (cam_dir.y - cam_pos.y));

	//scale.y = (cam_dir.x - cam_pos.x) * (cam_pos.y - p1.y) - (cam_dir.y - cam_pos.y) * (cam_pos.x * p1.x);
	//divid = (p2.y - p1.y) * (cam_dir.x - cam_pos.x) - (p2.x - p1.x) * (cam_dir.y - cam_pos.y);
	printf("sin_rot = %f, cos_rot = %f\n",sin_rot.y, cos_rot.y);
	printf("cam_dir.x = %f, cam_dir.y = %f\n", cam_dir.x, cam_dir.y);
	printf("scale.x = %f, scale.y = %f\n", scale.x, scale.y);
	printf("divid = %f\n", divid);
	return (intersect);
}

/*
t_vox cut_frustum_naze(t_vox cam_pos, t_pos cam_rot, t_vox p1, t_vox p2)
{
	SDL_Rect line;
	t_pos cos_rot;
	t_pos sin_rot;
	t_pos step;

	cos_rot.y = cos(cam_rot.y * M_PI_2);
	sin_rot.y = sin(cam_rot.y * M_PI_2);

	line.x = p1.x;
	line.y = pi.y;
	line.w = p2.x - p1.x;
	line.h = p2.x - p1.x;

	step.x = sin_rot / cos_rot;
	step.y = cos_rot / sin_rot;

	

}
*/
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
