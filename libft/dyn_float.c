/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:28:24 by msiesse           #+#    #+#             */
/*   Updated: 2019/07/08 13:41:56 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_dfloat(t_dfloat *d_arr)
{
	d_arr->arr = NULL;
	d_arr->size = 0;
	d_arr->capacity = 1;
}

void	change_dfloat(t_dfloat *d_arr, int add_size)
{
	double	*new_arr;
	int		new_size;
	int		i;

	new_size = d_arr->size + add_size;
	if (d_arr->capacity <= new_size)
	{
		while (d_arr->capacity <= new_size)
			d_arr->capacity *= 2;
		if (!(new_arr = (double*)malloc(sizeof(double) * d_arr->capacity)))
			err_mem();
		i = 0;
		while (d_arr->arr && i < d_arr->size)
		{
			new_arr[i] = d_arr->arr[i];
			i++;
		}
		free(d_arr->arr);
		d_arr->arr = new_arr;
	}
}

void	add_float_dfloat(t_dfloat *d_arr, double nb)
{
	change_dfloat(d_arr, 1);
	d_arr->arr[d_arr->size] = nb;
	d_arr->size++;
}

void	reinit_dfloat(t_dfloat *d_arr)
{
	free(d_arr->arr);
	d_arr->arr = NULL;
	d_arr->size = 0;
	d_arr->capacity = 1;
}
