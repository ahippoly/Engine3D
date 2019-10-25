/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:57:42 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/25 12:37:11 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	error_sdl(t_env *e)
{
	ft_printf("ERROR SDL (%s)", SDL_GetError());
	if (e->sdl.window != NULL)
		SDL_DestroyWindow(e->sdl.window);
	if (e->sdl.renderer != NULL)
		SDL_DestroyRenderer(e->sdl.renderer);
	SDL_Quit();
	exit(1);
}