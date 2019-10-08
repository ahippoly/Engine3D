/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:27:51 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:22:46 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	space_signe_double(t_param *params, long double num)
{
	if (num < 0)
		ft_putchar_params('-', params);
	else if (params->flag_plus)
		ft_putchar_params('+', params);
	else if (params->flag_space)
		ft_putchar_params(' ', params);
	return (0);
}

static int	pad_double(t_param *params, int *buff_pad)
{
	if (*buff_pad && params->flag_0 && !params->flag_min)
		while ((*buff_pad)-- > 0)
			ft_putchar_params('0', params);
	else if (*buff_pad > 0)
		while ((*buff_pad)-- > 0)
			ft_putchar_params(' ', params);
	return (0);
}

static int	print_double(t_param *params, long double num)
{
	int			len;
	static int	buff_pad;

	len = len_int(params, (long long)num);
	if (params->precis == -1)
		len += 7;
	else if (params->precis || (!params->precis && params->flag_diese))
		len += params->precis + 1;
	if (params->width > len)
		buff_pad = params->width - len - (params->flag_space
				|| params->flag_plus || (num < 0));
	if (params->flag_0)
		space_signe_double(params, num);
	if (!params->flag_min)
		pad_double(params, &buff_pad);
	if (!params->flag_0)
		space_signe_double(params, num);
	if (params->precis != -1)
		ft_putfloat(num, params->precis, params->flag_diese, params);
	else
		ft_putfloat(num, 6, params->flag_diese, params);
	pad_double(params, &buff_pad);
	return (0);
}

int			print_float(t_param *params, va_list ap)
{
	if (params->type == L)
		print_double(params, va_arg(ap, long double));
	else
		print_double(params, va_arg(ap, double));
	return (0);
}
