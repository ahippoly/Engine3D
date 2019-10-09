/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:40:05 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/09 13:55:42 by msiesse          ###   ########.fr       */
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
	}
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
