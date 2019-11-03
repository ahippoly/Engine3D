/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 01:19:12 by ahippoly          #+#    #+#             */
/*   Updated: 2019/09/21 19:38:42 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_pos	vox_on_screen(t_vox point, t_vox cam_pos, t_pos cam_rot)
{
	t_vox	diff;
	double	depth;
	t_pos	screen_pos;
	t_pos	sin_rot;
	t_pos	cos_rot;

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

void draw_texture(t_line top, t_line bot, char *img_files)
{
	double dist_top;
	double dist_bot;
	double step;
	t_memline top_tab;
	t_memline bot_tab;

	top_tab = mem_octant(top.pos1, top.pos2);
	bot_tab = mem_octant(bot.pos1, bot.pos2);
	
	


}
