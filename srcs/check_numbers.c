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

static t_bool	get_variable(t_env *e, char *p_c)
{
	char	c;
	char	nb[9];
	int	i;

	if (e->parsor.check_n[e->parsor.what_check] == 1)
		return (ERR_DOUBLE_DEF);
	c = *p_c;
	i = 0;
	while (c && c != '\n' && i < 8)
	{
		nb[i] = c;
		c = ft_fgetc(e->parsor.fd);
		i++;
	}
	nb[i] = 0;
	e->parsor.check_n[e->parsor.what_check] = 1;
	e->parsor.total_check++;
	e->n_list[e->parsor.what_check] = ft_atoi(nb);
	*p_c = c;
	return (0);
}

static t_bool	check_variable(t_env *e, char *p_c)
{
	char	c;

	c = ft_fgetc(e->parsor.fd);
	if (c == 'l')
		e->parsor.what_check = LINEDEF;
	else if (c == 'v')
		e->parsor.what_check = VERTEX;
	else if (c == 's')
	{
		c = ft_fgetc(e->parsor.fd);
		if (c == 'i')
			e->parsor.what_check = SIDEDEF;
		else if (c == 'e')
			e->parsor.what_check = SECTOR;
		else
			return (1);
	}
	else
		return (1);
	while (c && (c = ft_fgetc(e->parsor.fd)) != ' ')
		;
	if (!c)
		return (1);
	while ((c = ft_fgetc(e->parsor.fd)) == ' ')
		;
	*p_c = c;
	if (get_variable(e, p_c))
		return (ERR_DOUBLE_DEF);
	return (0);
}

static t_bool	check_number_line(t_env *e, char *p_c)
{
	char	c;
	int	check;

	c = *p_c;
	while (c && (c == ' ' || c == '\n'))
		c = ft_fgetc(e->parsor.fd);
	if (c != 'n')
		return (1);
	if ((c = ft_fgetc(e->parsor.fd)) != '_')
		return (1);
	*p_c = c;
	if ((check = check_variable(e, p_c)))
		return (check);
	if (e->parsor.total_check == 4)
		return (-1);
	return (0);
}

t_bool		check_numbers(t_env *e)
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
		return (res);
	return (0);
}
