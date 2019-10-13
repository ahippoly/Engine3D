/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:04:07 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/13 19:15:35 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

t_bool		get_vertex(t_env *e)
{
	t_bool		id;
	int		index;

	id = 0;
	index = get_the_number(e);
	if (is_saved(index, e->parsor.vertex_occ))
		return (0);
	add_elem_darr(&e->parsor.vertex_occ, &index);
	if (index < 0 || index >= e->n_list[VERTEX])
		exit_error(e, ERR_INDEX, "doom-nukem: index error");
	e->vertex_list[index].x = (float)get_the_number(e);
	e->vertex_list[index].y = (float)get_the_number(e);
	e->vertex_list[index].z = (float)get_the_number(e);
	while (e->parsor.pos == ' ')
		e->parsor.pos = ft_fgetc(e->parsor.fd);
	if (e->parsor.pos && e->parsor.pos != '\n')
		id = ERR_NOT_VALID_VERTEX;
	return (id);
}
