/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:02:07 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:26:59 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putfloat(long double x, int precision, int flag_diese
		, t_param *params)
{
	int i;

	if (precision == 0)
	{
		if (x - (long long)x > 0.5)
			x++;
		ft_putnbr_params_ll((long long)x, params);
		if (flag_diese)
			ft_putchar_params('.', params);
		return ;
	}
	ft_putnbr_params_ll((long long)x, params);
	ft_putchar_params('.', params);
	x -= (long long)x;
	i = 0;
	if ((long long)(x * (long double)ft_pow(10, precision + 1)) % 10 > 5)
		x += 1 / (long double)ft_pow(10, precision);
	while (i < precision)
	{
		x *= 10;
		ft_putnbr_params_ll((long long)x, params);
		x -= (long long)x;
		i++;
	}
}
