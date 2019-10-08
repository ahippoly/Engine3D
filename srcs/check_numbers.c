/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:43:17 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/08 16:17:03 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

t_bool	check_variable(t_env *e, char *p_c)
{
	char	c;

	c = ft_fgetc(e->parsor.fd);
	if (c == 'l')
		e->parsor.what_count = N_LINEDEF;
	else if (c == 'v')
		e->parsor.what_count = N_VERTEX;
	else if (c == 's')
	{
		c = ft_fgetc(e->parsor.fd);
		if (c == 'i')
			e->parsor.what_count = N_SIDEDEF;
		else if (c == 'e')
			e->parsor.what_count = N_SECTOR;
		else
			return (1);
	}
	else
		return (1);
	while (c && (c = ft_fgetc(e->parsor.fd)) != ' ')
		;
	if (!c)
		return (1);
	while (c && (c = ft_fgetc(e->parsor.fd)) == ' ')
		;
	
}

t_bool	check_number_line(t_env *e, char *p_c)
{
	char	c;

	c = *p_c;
	while (c && (c == ' ' || c == '\n')
		c = ft_fgetc(e->parsor.fd);
	if (c != 'n')
		return (1);
	if ((c = ft_fgetc(e->parsor.fd)) != '_')
		return (1);
	*p_c = c;
	if (check_variable(e, p_c))
		return (1);
}

t_bool	check_numbers(t_env *e)
{
	char	c;
	t_bool	res;

	while (((c = ft_fgetc(e->parsor.fd)) == ' ' || c == '\n') && c)
		;
	if (!c)
		return (1);
	while ((res = check_number_line(e, &c)) != 0)
		;
	if (res != -1)
		return (res)
	return (0);
}
