/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sidedef.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:57:27 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/28 18:28:40 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static t_bool	get_more_sidedef(t_env *e, int index)
{
	t_portal	portal;

	while (e->parsor.pos == ' ')
		e->parsor.pos = ft_fgetc(e->parsor.fd);
	if (!e->parsor.pos)
		return (ERR_NOT_VALID_SIDEDEF);
	if (e->parsor.pos == '\n')
		return (0);
	if (e->parsor.pos == 'p')
	{
		portal.sidedef_root = index;
		portal.sidedef_dest = get_the_number(e);
		*((t_portal*)e->sidedef_list[index].data) = portal;
		e->sidedef_list[index].size_data = sizeof(t_portal);
	}
	else
		return (ERR_NOT_VALID_SIDEDEF);
	return (0);
}

t_bool			get_sidedef(t_env *e)
{
	t_bool		id;
	int		index;

	id = 0;
	index = get_the_number(e);
	if (is_saved(index, e->parsor.sidedef_occ))
		return (0);
	add_elem_darr(&e->parsor.sidedef_occ, &index);
	if (index < 0 || index >= e->n_list[SIDEDEF])
		exit_error(e, ERR_INDEX, "doom-nukem: index error");
	e->sidedef_list[index].up_texture = get_the_number(e);
	e->sidedef_list[index].low_texture = get_the_number(e);
	e->sidedef_list[index].middle_texture = get_the_number(e);
	e->sidedef_list[index].sector_id = get_the_number(e);
	e->sidedef_list[index].linedef_id = get_the_number(e);
	id = get_more_sidedef(e, index);
	while (e->parsor.pos == ' ')
		e->parsor.pos = ft_fgetc(e->parsor.fd);
	if (e->parsor.pos && e->parsor.pos != '\n')
		id = ERR_NOT_VALID_SIDEDEF;
	return (id);
}
