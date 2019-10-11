/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_things_parsor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:08:47 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/11 14:45:42 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

int	get_the_number(t_env *e)
{
	char	str_nb[9];
	int	nb;
	int	i;

	while (e->parsor.pos && e->parsor.pos != ' ' && e->parsor.pos != '\n')
		e->parsor.pos = ft_fgetc(e->parsor.fd);
	while (e->parsor.pos == ' ')
		e->parsor.pos = ft_fgetc(e->parsor.fd);
	i = 0;
	if (e->parsor.pos == '\n')
		exit_error(e, ERR_SYNTAX, "doom-nukem: syntax error");
	while (e->parsor.pos && e->parsor.pos != ' ' && e->parsor.pos != '\n' && i < 8)
	{
		str_nb[i] = e->parsor.pos;
		e->parsor.pos = ft_fgetc(e->parsor.fd);
		i++;
	}
	str_nb[i] = 0;
	if (e->parsor.pos && e->parsor.pos != ' ' && e->parsor.pos != '\n')
		exit_error(e, ERR_TOO_BIG_DATA, "doom-nukem: data is too big");
	nb = ft_atoi(str_nb);
	return (nb);
}
