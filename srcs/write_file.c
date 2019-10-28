/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:38:48 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/28 11:33:33 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include <unistd.h>

void	write_file(t_env *e)
{
	int		i;

	i = 0;
	ft_putstr_fd("id	x1	y1	x2	y2\n", e->fd);
	write(e->fd, e->sec[e->secteur].file, ft_strlen(e->sec[e->secteur].file));
	free(e->sec[e->secteur].file);
	close(e->fd);
}