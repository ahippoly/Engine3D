/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:54:40 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:22:19 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pad_c(t_param *params, int *buff_pad)
{
	if (*buff_pad && params->flag_0 && !params->flag_min)
		while ((*buff_pad)-- > 0)
			ft_putchar_params('0', params);
	else if (*buff_pad > 0)
		while ((*buff_pad)-- > 0)
			ft_putchar_params(' ', params);
	return (0);
}

static int	print_c(t_param *params, char c)
{
	static int	buff_pad;

	if (params->width > 0)
		buff_pad = params->width - 1;
	if (!params->flag_min)
		pad_c(params, &buff_pad);
	ft_putchar_params(c, params);
	pad_c(params, &buff_pad);
	return (0);
}

int			print_char(t_param *params, va_list ap)
{
	if (params->percent)
		print_c(params, '%');
	else
		print_c(params, va_arg(ap, int));
	return (0);
}
