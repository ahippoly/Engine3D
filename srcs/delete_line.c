/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <ceaudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:48:27 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/10/28 15:59:18 by ceaudouy         ###   ########.fr       */
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
	char	*new;
	char	*tmp;

	i = 0;
	j = 0;
	if (!(new = (char*)malloc(sizeof(*new) * e->sec[e->secteur].i_file)))
		error(e);
	printf("i_back = %d\n", e->i_back);
	while (e->i_back > 0 && e->sec[e->secteur].file[e->i_back] != '\n')
		e->i_back--;
	//ft_putstr(e->sec[e->secteur].file);
	//ft_putchar('\n');
	while (e->sec[e->secteur].file[i])
	{
		if (i == e->i_back)
		{
			i++;
			while (e->sec[e->secteur].file[i] != '\n')
				i++;
		}
		new[j] = e->sec[e->secteur].file[i];
		i++;
		j++;
	}
	new[j] = '\0';
	//ft_putstr(new);
	//ft_putchar('\n');
	tmp = e->sec[e->secteur].file;
	e->sec[e->secteur].file = new;
	//i = 0;
	//e->sec[e->secteur].i_file--;
	//e->sec[e->secteur].file = new;
	//while (new[i])
	//{
	//	e->sec[e->secteur].file[i] = new[i];
	//	i++;
	//}
	//free(tmp);
	redraw(e);
}