/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_linedef.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:48:13 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/11 16:00:14 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

t_bool	get_linedef(t_env *e)
{
	t_bool		id;
	int		index;

	id = 0;
	index = get_the_number(e);
	if (index < 0 || index >= e->n_list[LINEDEF])
		exit_error(e, ERR_INDEX, "doom-nukem: index error");
	e->linedef_list[index].start = get_the_number(e);
	e->linedef_list[index].end = get_the_number(e);
	e->linedef_list[index].type = get_the_number(e);
	e->linedef_list[index].sector_tag = get_the_number(e);
	e->linedef_list[index].right_sidedef = get_the_number(e);
	e->linedef_list[index].left_sidedef = get_the_number(e);
	while (e->parsor.pos == ' ')
		e->parsor.pos = ft_fgetc(e->parsor.fd);
	if (e->parsor.pos && e->parsor.pos != '\n')
		id = ERR_NOT_VALID_LINEDEF;
	return (id);
}
