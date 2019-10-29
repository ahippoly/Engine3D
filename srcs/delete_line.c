/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:48:27 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/29 15:34:59 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	redraw(t_env *e)
{
	//ft_putstr(e->sec[e->secteur].file);
	//ft_putchar('\n');
	clear(e);;;
	draw_ver(e);
	edit_draw(e);
	print(e);
}

void	delete_line(t_env *e)
{
	int		i;
	int		j;
	int		n;
	char	*new;
	char	*tmp;

	i = 0;
	j = 0;
	n = 0;
	tmp = e->sec[e->secteur].file ;
	if (!(new = (char*)malloc(sizeof(*new) * ft_strlen(e->sec[e->secteur].file))))
		error(e);
	while (e->sec[e->secteur].file[i])
	{
		if (e->sec[e->secteur].file[i] == '\n')
			n++;
		if (n == e->sec[e->secteur].line)
		{
			i++;
			n++;
			while (e->sec[e->secteur].file[i] != '\n')
				i++;
		}
		new[j] = e->sec[e->secteur].file[i];
		i++;
		j++;
	}
	while (j < i)
		new[j++] = '\0';
	e->sec[e->secteur].file = new;
	e->sec[e->secteur].i_file--;
	ft_bzero(tmp, ft_strlen(tmp));
	free(tmp);
	redraw(e);
}