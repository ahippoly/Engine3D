/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:44:54 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/28 18:25:43 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_env	e;

	init_env(&e);
	if ((e.parsor.fd = open(av[1], O_RDONLY)) == -1)
		exit(1);
	doom_parsor(&e);
	(void)ac;
	for (int i = 0; i < e.n_list[SECTOR]; i++)
		printf("sector %d: floor_height: %hd; ceil_height: %hd; floor_texture: %hd; ceil_texture: %hd; light_level: %hd; type: %hu\n", i, e.sector_list[i].floor_height,
				e.sector_list[i].ceil_height, e.sector_list[i].floor_texture, e.sector_list[i].ceil_texture, e.sector_list[i].light_lvl, e.sector_list[i].type);
	ft_putchar('\n');
	for (int i = 0; i < e.n_list[VERTEX]; i++)
		printf("vertex: %d: x: %f; y: %f; z: %f\n", i, e.vertex_list[i].x, e.vertex_list[i].y, e.vertex_list[i].z);
	ft_putchar('\n');
	for (int i = 0; i < e.n_list[LINEDEF]; i++)
	{
		printf("linedef %d: start = %u; end = %u; type = %hd; sector_tag = %hd; right_sidedef = %hd; left_linedef = %hd\n", i, e.linedef_list[i].start,
				e.linedef_list[i].end, e.linedef_list[i].type, e.linedef_list[i].sector_tag, e.linedef_list[i].right_sidedef, e.linedef_list[i].left_sidedef) ;
	}
	ft_putchar('\n');
	for (int i = 0; i < e.n_list[SIDEDEF]; i++)
	{
		printf("sidedef %d: up_texture = %hd; low_texture = %hd; mid_texture = %hd; sector_id = %hu\n", i, e.sidedef_list[i].up_texture, e.sidedef_list[i].low_texture, e.sidedef_list[i].middle_texture, e.sidedef_list[i].sector_id) ;

	}
	return (0);
}
