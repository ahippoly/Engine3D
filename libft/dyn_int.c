/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:33:09 by msiesse           #+#    #+#             */
/*   Updated: 2019/07/08 12:27:32 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_dint(t_dint *d_arr)
{
	d_arr->arr = NULL;
	d_arr->size = 0;
	d_arr->capacity = 1;
}

void	change_dint(t_dint *d_arr, int add_size)
{
	int	*new_arr;
	int	new_size;
	int	i;

	new_size = d_arr->size + add_size;
	if (d_arr->capacity <= new_size)
	{
		while (d_arr->capacity <= new_size)
			d_arr->capacity *= 2;
		if (!(new_arr = (int*)malloc(sizeof(int) * d_arr->capacity)))
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

void	add_integer_dint(t_dint *d_arr, int nb)
{
	change_dint(d_arr, 1);
	d_arr->arr[d_arr->size] = nb;
	d_arr->size++;
}

void	add_array_dint(t_dint *d_arr, int *arr_nb, int size)
{
	int	i;

	i = 0;
	change_dint(d_arr, size);
	while (i < size)
	{
		d_arr->arr[d_arr->size] = arr_nb[i];
		i++;
		d_arr->size++;
	}
}

void	reinit_dint(t_dint *d_arr)
{
	free(d_arr->arr);
	d_arr->arr = NULL;
	d_arr->size = 0;
	d_arr->capacity = 1;
}
