/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:45:20 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/09 13:47:45 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	init_env(t_env *e)
{
	e->vertex_list = NULL;
	e->sidedef_list = NULL;
	e->linedef_list = NULL;
	e->sector_list = NULL;
}
