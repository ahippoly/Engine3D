/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:29:51 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/11/14 11:30:36 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
void    init2(t_env *e)
{
    int     i;

    i = 0;
    while (i <= 10)
    {
        if (!(e->sec[i].file = (char*)malloc(sizeof(*e->sec[i].file) * 2)))
		    exit (1);
	    e->sec[i].file[1] = 0;
	    if (!(e->sec[i].pixels = (char*)malloc(H_IMG * W_IMG * 4)))
            exit (1);
		e->sec[i].i_file = 0;
	    i++;
    }
}

void	init(t_env *e)
{
	e->set_wall = 0;
	e->set_map = 0;
	e->edit_id = 0;
	e->map.x = 0;
	e->map.y = 0;
	e->map.h = H_WIN;
	e->map.w = W_WIN;
	e->select = 0;
	e->select_line = 0;
	e->secteur = 0;
	e->info = 0;
	init2(e);
}

void	free_all(t_env *e)
{
	int		i;

	i = 0;
	while (i <= 10)
	{
		free(e->sec[i].file);
		free(e->sec[i].pixels);
		i++;
	}
	exit(0);
}