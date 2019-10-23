/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:56:34 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/05 13:12:15 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char		ft_fgetc(const int fd)
{
	char	c;
	int		size;

	if (fd < 0)
		return (ERR_FD_OPEN);
	if ((size = read(fd, &c, sizeof(c))) < 0)
		return (ERR_FD_READ);
	if (size == 0)
		return (0);
	return (c);
}
