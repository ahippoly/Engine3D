/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_doom_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:57:18 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/13 19:17:21 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static t_bool	get_doom_data_line(t_env *e)
{
	t_bool	id;

	id = 0;
	while (e->parsor.pos == '\n' || e->parsor.pos == ' ')
		e->parsor.pos = ft_fgetc(e->parsor.fd);
	if (e->parsor.pos == 'v')
		id = get_vertex(e);
	else if (e->parsor.pos == 'l')
		id = get_linedef(e);
	else if (e->parsor.pos == 's')
	{
		if ((e->parsor.pos = ft_fgetc(e->parsor.fd)) == 'e')
			id = get_sector(e);
		else if (e->parsor.pos == 'i')
			id = get_sidedef(e);
	}
	else
	{
		while (e->parsor.pos && (e->parsor.pos = ft_fgetc(e->parsor.fd)) != '\n'
			&& e->parsor.pos != ' ')
			;
	}
	if (e->parsor.pos == 0)
		return (-1);
	return (id);
}

t_bool		get_doom_data(t_env *e)
{
	t_bool	id;

	while (!(id = get_doom_data_line(e)))
		;
	if (id != -1 && id >= 4)
		exit_error(e, id, "doom-nukem: can't get the data");
	return (0);
}
