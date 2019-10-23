/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:58:19 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/22 13:50:53 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include <unistd.h>
#include <fcntl.h>

void	init(t_env *e)
{
	e->set_wall = 0;
	e->set_map = 0;
	e->i_file = 0;
	e->edit_id = 0;
	e->map.x = 0;
	e->map.y = 0;
	e->map.h = H_WIN;
	e->map.w = W_WIN;
	e->select = 0;
	e->select_line = 0;
}

int		create_fd()
{
	int	fd;

	fd = creat("edit.map", S_IRUSR | S_IWUSR);
	return (fd);
}

void	file_edit(t_env *e)
{
	if (!(e->file = (char**)malloc(sizeof(*e->file) * 2)))
		exit (1);
	e->file[1] = 0;
}

void	set_sdl(t_env *e)
{
	init(e);
	e->fd = create_fd();
	if (e->fd < 0)
		exit(1);
	file_edit(e);
	e->sdl.quit = SDL_FALSE;
	e->sdl.window = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, W_WIN, H_WIN, SDL_WINDOW_OPENGL);
	if(e->sdl.window == NULL)
		error_sdl(e);
	e->sdl.renderer = SDL_CreateRenderer(e->sdl.window, -1, SDL_RENDERER_SOFTWARE);
	if (e->sdl.renderer == NULL)
		error_sdl(e);
	e->sdl.texture = SDL_CreateTexture(e->sdl.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, W_IMG, H_IMG);
	if (e->sdl.texture == NULL)
		error_sdl(e);
	if (SDL_SetTextureBlendMode(e->sdl.texture, SDL_BLENDMODE_BLEND) != 0)
		error_sdl(e);
	e->sdl.pixels = (char*)malloc(H_IMG * W_IMG * 4);
	while(!e->sdl.quit)
	{
		
		SDL_WaitEvent(&e->sdl.event);
		if (e->sdl.event.type == SDL_QUIT)
			e->sdl.quit = SDL_TRUE;	
		else if (e->sdl.event.type == SDL_KEYDOWN)
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
		SDL_RenderClear(e->sdl.renderer);
		SDL_UpdateTexture(e->sdl.texture, NULL, e->sdl.pixels, W_IMG * 4);
		if (SDL_RenderCopy(e->sdl.renderer, e->sdl.texture, &e->map, NULL) != 0)
			error_sdl(e);
		SDL_RenderPresent(e->sdl.renderer);
		}
		editor(e);
	}
	SDL_DestroyWindow(e->sdl.window);
	SDL_DestroyTexture(e->sdl.texture);
	SDL_Quit();
}


int		main()
{
	t_env e;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{   
		ft_printf("Error Initialisation SDl (%s)", SDL_GetError());
		return (-1);
	}
	set_sdl(&e);
	return (0);
}