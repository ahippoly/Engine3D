/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_doom_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:57:18 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/11 16:01:04 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static t_bool	get_doom_data_line(t_env *e)
{
	t_bool	id;

	id = ERR_NOT_VALID_STRUCT;
	while (e->parsor.pos == '\n' || e->parsor.pos == ' ')
		e->parsor.pos = ft_fgetc(e->parsor.fd);
	if (e->parsor.pos == 'v')
		id = get_vertex(e);
	if (e->parsor.pos == 'l')
		id = get_linedef(e);
	if (e->parsor.pos == 0)
		return (-1);
	return (id);
}

t_bool		get_doom_data(t_env *e)
{
	t_bool	id;

	while (!(id = get_doom_data_line(e)))
		;
	if (id != -1 && id == ERR_NOT_VALID_LINEDEF)
		exit_error(e, id, "doom-nukem: can't get the data");
	return (0);
}
