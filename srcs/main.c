/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:44:54 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/11 16:06:12 by msiesse          ###   ########.fr       */
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
	for (int i = 0; i < 4; i++)
	{
		printf("linedef %d: start = %u; end = %u; type = %hd; sector_tag = %hd; right_linedef = %hd; left_linedef = %hd\n", i, e.linedef_list[i].start,
				e.linedef_list[i].end, e.linedef_list[i].type, e.linedef_list[i].sector_tag, e.linedef_list[i].right_sidedef, e.linedef_list[i].left_sidedef) ;
	}
	return (0);
}
