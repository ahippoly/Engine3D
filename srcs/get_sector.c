/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:48:14 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/28 18:26:23 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

t_bool	get_sector(t_env *e)
{
	t_bool		id;
	int		index;

	id = 0;
	index = get_the_number(e);
	if (is_saved(index, e->parsor.sector_occ))
		return (0);
	add_elem_darr(&e->parsor.sector_occ, &index);
	if (index < 0 || index >= e->n_list[SECTOR])
		exit_error(e, ERR_INDEX, "doom-nukem: index error");
	e->sector_list[index].floor_height = get_the_number(e);
	e->sector_list[index].ceil_height = get_the_number(e);
	e->sector_list[index].floor_texture = get_the_number(e);
	e->sector_list[index].ceil_texture = get_the_number(e);
	e->sector_list[index].light_lvl = get_the_number(e);
	e->sector_list[index].type = get_the_number(e);
	e->sector_list[index].start_sidedef = get_the_number(e);
	e->sector_list[index].end_sidedef = get_the_number(e);
	while (e->parsor.pos == ' ')
		e->parsor.pos = ft_fgetc(e->parsor.fd);
	if (e->parsor.pos && e->parsor.pos != '\n')
		id = ERR_NOT_VALID_LINEDEF;
	return (id);
}
