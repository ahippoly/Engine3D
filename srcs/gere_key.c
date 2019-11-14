/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:05:11 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/11/14 11:30:59 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void    gere_key3(t_env *e)
{
	if (e->sdl.event.key.keysym.scancode == 58)
	{
		if (e->select == 1 && e->find_line == 1)
			e->info ^= 1;
	}
}


void    gere_key2(t_env *e)
{
	if (e->sdl.event.key.keysym.scancode == 20 && e->sec[e->secteur].i_file > 0) //select ligne
    {
    	e->set_wall = 0;
    	e->select ^= 1;
		e->find_line = 0;
    	e->info = 0;
    	if (e->select == 0)
    		e->edit_id = e->tmp_id;
		clear(e);
		draw_ver(e);
		edit_draw(e);
	}
	if (e->sdl.event.key.keysym.scancode == 87) // ++secteur
		if (e->secteur < 10)
		{
			e->secteur++;
    		clear(e);
			draw_ver(e);
			edit_draw(e);
			e->set_wall = 0;
		}
	if (e->sdl.event.key.keysym.scancode == 86) // --secteur
		if (e->secteur > 0)
		{
 	   		e->set_wall = 0;
			e->secteur--;
 	   		clear(e);
			draw_ver(e);
			edit_draw(e);
		}
}

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
	gere_key2(e);
	gere_key3(e);
   	// ft_putnbr(e->sdl.event.key.keysym.scancode);
	//ft_putchar('\n');
	print(e);
}