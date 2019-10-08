/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:51:54 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/08 14:07:14 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_darr(t_darr *d_arr, int size_type)
{
	d_arr->arr = NULL;
	d_arr->size = 0;
	d_arr->capacity = 1;
	d_arr->size_type = size_type;
}

void	change_darr(t_darr *d_arr, int add_size)
{
	void	*new_arr;
	int	new_size;
	int	i;

	new_size = d_arr->size + add_size;
	if (d_arr->capacity <= new_size)
	{
		while (d_arr->capacity <= new_size)
			d_arr->capacity *= 2;
		if (!(new_arr = malloc(d_arr->size_type * d_arr->capacity)))
			err_mem();
		i = 0;
		ft_memmove(new_arr, d_arr->arr, d_arr->size_type * d_arr->size);
		free(d_arr->arr);
		d_arr->arr = new_arr;
	}
}

void	add_elem_darr(t_darr *d_arr, void *elem)
{
	change_darr(d_arr, 1);
	ft_memmove((char*)d_arr->arr + (d_arr->size * d_arr->size_type), elem, d_arr->size_type);
	d_arr->size++;
}

void	reinit_darr(t_darr *d_arr, int size_type)
{
	free(d_arr->arr);
	d_arr->arr = NULL;
	d_arr->size = 0;
	d_arr->capacity = 1;
	d_arr->size_type = size_type;
}
