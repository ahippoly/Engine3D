/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:48:27 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/25 15:49:37 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	redraw(t_env *e)
{
	clear(e);;;
	draw_ver(e);
	edit_draw(e);
	print(e);
}

void	delete_line(t_env *e)
{
	int		i;
	int		j;
	char	**new;
	char	**tmp;

	i = 0;
	j = 0;
	if (!(new = (char**)malloc(sizeof(*new) * e->sec[e->secteur].i_file)))
		error(e);
	while (i < e->sec[e->secteur].i_file)
	{
		if (i == e->sec[e->secteur].line)
		{
			free(e->sec[e->secteur].file[i]);
			i++;
		}
		new[j] = e->sec[e->secteur].file[i];
		i++;
		j++;
	}
	new[j] = 0;
	tmp = e->sec[e->secteur].file;
	i = 0;
	e->sec[e->secteur].i_file--;
	e->sec[e->secteur].file = new;
	while (i < e->sec[e->secteur].i_file)
	{
		e->sec[e->secteur].file[i] = new[i];
		i++;
	}
	free(tmp);
	redraw(e);
}