/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:05:11 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/30 12:17:16 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void    gere_key(t_env *e)
{
    if (e->sdl.event.key.keysym.scancode == 41) //quit program
		e->sdl.quit = SDL_TRUE;	
	if (e->sdl.event.key.keysym.scancode == 40) //ecrit coordonnee 
		write_file(e);
	if (e->sdl.event.key.keysym.scancode == 98)	//select wall 1
		e->edit_id = 0;
	if (e->sdl.event.key.keysym.scancode == 89) // select wall 2
		e->edit_id = 1;
	if (e->sdl.event.key.keysym.scancode == 90) // select wall 3
		e->edit_id = 2;
	if (e->sdl.event.key.keysym.scancode == 82) //move map 
		if (e->map.y > 10)
			e->map.y -= 10;
	if (e->sdl.event.key.keysym.scancode == 81) // move map
		if (e->map.y < 480)
			e->map.y += 10;
	if (e->sdl.event.key.keysym.scancode == 80) // move map
		if (e->map.x > 10)
			e->map.x -= 10;
	if (e->sdl.event.key.keysym.scancode == 79) // move map
		if (e->map.x < 960)
			e->map.x += 10;
    if (e->sdl.event.key.keysym.scancode == 42 && e->sec[e->secteur].i_file > 0 && e->select == 0) //effacer dernier ligne
    	draw_back(e);
    if (e->sdl.event.key.keysym.scancode == 42 && e->sec[e->secteur].i_file > 0 && e->select == 1)	//effacer ligne select
    	delete_line(e);
    if (e->sdl.event.key.keysym.scancode == 20 && e->sec[e->secteur].i_file > 0) //select ligne
    {
    	e->set_wall = 0;
    	e->select ^= 1;
    	if (e->select == 0)
    		e->edit_id = e->tmp_id;
		clear(e);
		draw_ver(e);
		edit_draw(e);
	}
	if (e->sdl.event.key.keysym.scancode == 87)
		if (e->secteur < 10)
		{
			e->secteur++;
    		clear(e);
			draw_ver(e);
			edit_draw(e);
			e->set_wall = 0;
		}
	if (e->sdl.event.key.keysym.scancode == 86)
		if (e->secteur > 0)
		{
 	   		e->set_wall = 0;
			e->secteur--;
 	   		clear(e);
			draw_ver(e);
			edit_draw(e);
		}
	printf("e->secteur = %d\n", e->secteur);
    print(e);
}