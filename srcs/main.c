/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:44:54 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/09 13:45:08 by msiesse          ###   ########.fr       */
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
		ft_printf("%d\n", e.n_list[i]);
	return (0);
}
