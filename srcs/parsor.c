/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:10:34 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/11 14:33:37 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void	init_parsor(t_parsor *parsor)
{
	ft_bzero(parsor->count, sizeof(int) * 4);
	ft_bzero(parsor->check_n, sizeof(t_bool) * 4);
	parsor->total_check = 0;
	parsor->what_check = 0;
}

static void	init_lists(t_env *e)
{
	if (!(e->vertex_list = (t_vertex*)malloc(sizeof(t_vertex) * e->n_list[VERTEX])))
		exit_error(e, ERR_MEM_LISTS, "doom-nukem: allocation error");
	if (!(e->sector_list = (t_sector*)malloc(sizeof(t_sector) * e->n_list[SECTOR])))
		exit_error(e, ERR_MEM_LISTS, "doom-nukem: allocation error");
	if (!(e->linedef_list = (t_linedef*)malloc(sizeof(t_linedef) * e->n_list[LINEDEF])))
		exit_error(e, ERR_MEM_LISTS, "doom-nukem: allocation error");
	if (!(e->sidedef_list = (t_sidedef*)malloc(sizeof(t_sidedef) * e->n_list[SIDEDEF])))
		exit_error(e, ERR_MEM_LISTS, "doom-nukem: allocation error");
}

void	doom_parsor(t_env *e)
{
	int	id;

	init_parsor(&e->parsor);
	if (check_numbers(e))
		exit_error(e, ERR_COUNTING, "doom-nukem: counting error");
	init_lists(e);
	if ((id = get_doom_data(e)) != 0)
		exit_error(e, id, "doom-nukem: error in data points");
}
