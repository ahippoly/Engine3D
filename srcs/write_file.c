/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:38:48 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/23 11:05:13 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include <unistd.h>

void	write_file(t_env *e)
{
	int		i;

	i = 0;
	ft_putstr_fd("id	x1	y1	x2	y2\n", e->fd);
	while (i < e->i_file)
	{
		write(e->fd, e->file[i], ft_strlen(e->file[i]));
		free(e->file[i]);
		i++;
	}
	close(e->fd);
	free(e->file);
}