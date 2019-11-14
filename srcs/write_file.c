/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:38:48 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/11/14 11:32:05 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include <unistd.h>

void	write_file(t_env *e)
{
	int		i;

	i = 0;
	while (i <= 10)
	{
		ft_putstr_fd("\nsecteur: ", e->fd);
		ft_putnbr_fd(i, e->fd);
		ft_putstr_fd("\nid	x1	y1	x2	y2\n", e->fd);
		write(e->fd, e->sec[i].file, ft_strlen(e->sec[i].file));
		i++;
	}
	close(e->fd);
}