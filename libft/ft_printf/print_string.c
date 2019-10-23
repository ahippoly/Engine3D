/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:28:36 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:23:43 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

static int	pad_string(t_param *params, int *buff_pad)
{
	if (*buff_pad && params->flag_0 && !params->flag_min)
		while ((*buff_pad)-- > 0)
			ft_putchar_params('0', params);
	else if (*buff_pad > 0)
		while ((*buff_pad)-- > 0)
			ft_putchar_params(' ', params);
	return (0);
}

static int	print_s(t_param *params, char *s)
{
	int			len;
	static int	buff_pad;

	if (s)
		len = ft_strlen(s);
	else
		len = 6;
	if (params->precis < len && params->precis != -1)
		len = params->precis;
	if (params->width > len)
		buff_pad = params->width - len;
	if (!params->flag_min)
		pad_string(params, &buff_pad);
	if (s)
		write(1, s, len);
	else
		write(1, "(null)", len);
	params->num += len;
	pad_string(params, &buff_pad);
	return (0);
}

int			print_string(t_param *params, va_list ap)
{
	print_s(params, va_arg(ap, char *));
	return (0);
}
