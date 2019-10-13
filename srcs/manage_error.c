/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:40:05 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/13 18:41:24 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	exit_error(t_env *e, int id, const char *msg)
{
	if (id >= 3)
	{
		free(e->vertex_list);
		free(e->sector_list);
		free(e->linedef_list);
		free(e->sidedef_list);
		reinit_darr(&e->parsor.sector_occ, 0);
		reinit_darr(&e->parsor.vertex_occ, 0);
		reinit_darr(&e->parsor.linedef_occ, 0);
		reinit_darr(&e->parsor.sidedef_occ, 0);
	}
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
