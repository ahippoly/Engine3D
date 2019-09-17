/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:58:19 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/09/17 14:26:52 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	set_sdl(t_env *e)
{
	e->sdl.quit = SDL_FALSE;
	
	e->sdl.window = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, W_WIN, H_WIN, SDL_WINDOW_OPENGL);
	if(e->sdl.window == NULL)
		error_sdl(e);
	e->sdl.renderer = SDL_CreateRenderer(e->sdl.window, -1, SDL_RENDERER_SOFTWARE);
	if (e->sdl.renderer == NULL)
		error_sdl(e);
	while(!e->sdl.quit)
	{
		SDL_WaitEvent(&e->sdl.event);
			if (e->sdl.event.type == SDL_QUIT)
				e->sdl.quit = SDL_TRUE;	
			else if (e->sdl.event.type == SDL_KEYDOWN)
			{	
				if (e->sdl.event.key.keysym.scancode == 41)
					e->sdl.quit = SDL_TRUE;	
			}
			editor(e);
	}
	SDL_DestroyWindow(e->sdl.window);
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