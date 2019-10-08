/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fgetc_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:32 by msiesse           #+#    #+#             */
/*   Updated: 2019/06/30 22:27:37 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	fgetc_pars(const int fd, const char *charset)
{
	char	c;
	int		size;

	if (fd < 0)
		return (ERR_FD_OPEN);
	if ((size = read(fd, &c, sizeof(c))) < 0)
		return (ERR_FD_READ);
	if (size == 0)
		return (0);
	if (!(ft_strchr(charset, c)))
		return (ERR_NOT_IN_CHARSET);
	return (c);
}
