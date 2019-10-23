/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:34:54 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:23:21 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			len_int(t_param *params, long long num)
{
	if (params->precis)
	{
		if (params->type == hh)
			return (size_number((char)num, 10));
		else if (params->type == h)
			return (size_number((short)num, 10));
		else if (params->type == r)
			return (size_number((int)num, 10));
		else if (params->type == l)
			return (size_number((long)num, 10));
		else
			return (size_number((long long)num, 10));
	}
	return (0);
}

static int	space_signe(t_param *params, long long num)
{
	if (num < 0)
		ft_putchar_params('-', params);
	else if (params->flag_plus)
		ft_putchar_params('+', params);
	else if (params->flag_space)
		ft_putchar_params(' ', params);
	return (0);
}

static int	pad(t_param *params, int *buff_pad, int *buff_prec)
{
	if (*buff_pad && params->precis == -1 && params->flag_0
			&& !params->flag_min)
		while ((*buff_pad)-- > 0)
			ft_putchar_params('0', params);
	else if (*buff_pad > 0)
		while ((*buff_pad)-- > 0)
			ft_putchar_params(' ', params);
	*buff_pad = 0;
	if (*buff_prec < 0)
		*buff_prec = 0;
	return (0);
}

static int	print_int(t_param *params, long long num)
{
	int			len;
	static int	buff_prec;
	static int	buff_pad;

	len = len_int(params, num);
	if (params->precis > len)
		buff_prec = params->precis - len;
	if (params->width > params->precis)
		buff_pad = params->width - buff_prec - len - (params->flag_space
				|| params->flag_plus || (num < 0));
	if (params->precis == -1 && params->flag_0)
		space_signe(params, num);
	if (!params->flag_min)
		pad(params, &buff_pad, &buff_prec);
	if (!params->flag_0 || params->precis >= 0)
		space_signe(params, num);
	while (buff_prec-- > 0)
		ft_putchar_params('0', params);
	ft_gputnbr(&num, params);
	pad(params, &buff_pad, &buff_prec);
	return (0);
}

int			print_dec(t_param *params, va_list ap)
{
	int		cast1;

	if (params->type == hh)
	{
		cast1 = va_arg(ap, int);
		print_int(params, (char)cast1);
	}
	else if (params->type == h)
	{
		cast1 = va_arg(ap, int);
		print_int(params, (short)cast1);
	}
	if (params->type == r)
		print_int(params, va_arg(ap, int));
	else if (params->type == l)
		print_int(params, va_arg(ap, long));
	else if (params->type == ll)
		print_int(params, va_arg(ap, long long));
	return (0);
}
