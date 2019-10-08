/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:50:49 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:24:33 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		len_unsigned(t_param *params, unsigned long long num, int base)
{
	if (params->precis)
	{
		if (params->type == ll)
			return (size_u_number((unsigned long long)num, base));
		else if (params->conv == 'p')
			return (size_u_number((unsigned long long)num, base));
		else if (params->type == hh)
			return (size_u_number((unsigned char)num, base));
		else if (params->type == h)
			return (size_u_number((unsigned short)num, base));
		else if (params->type == r)
			return (size_u_number((unsigned int)num, base));
		else if (params->type == l)
			return (size_u_number((unsigned long)num, base));
	}
	return (0);
}

static int		print_diese(t_param *params)
{
	if (params->conv == 'o')
		ft_putchar_params('0', params);
	else if (params->conv == 'x' || params->conv == 'X')
	{
		ft_putchar_params('0', params);
		ft_putchar_params(params->conv, params);
	}
	else if (params->conv == 'p')
		ft_putstr_params("0x", params);
	return (0);
}

static int		pad_u(t_param *params, int *buff_pad, int *buff_prec)
{
	if (*buff_pad > 0 && params->precis == -1 && params->flag_0
			&& !params->flag_min)
	{
		if (params->flag_diese || params->conv == 'p')
		{
			print_diese(params);
			params->flag_diese = 0;
			if (params->conv == 'p')
				params->conv = 'P';
		}
		while ((*buff_pad)-- > 0)
			ft_putchar_params('0', params);
	}
	else if (*buff_pad > 0)
		while ((*buff_pad)-- > 0)
			ft_putchar_params(' ', params);
	*buff_pad = 0;
	if (*buff_prec < 0)
		*buff_prec = 0;
	return (0);
}

static int		print_unsigned(t_param *params, unsigned long long num)
{
	int			len;
	static int	buff_prec;
	static int	buff_pad;

	if (params->conv == 'o')
		len = len_unsigned(params, num, 8);
	else if (params->conv == 'x' || params->conv == 'X' || params->conv == 'p')
		len = len_unsigned(params, num, 16);
	else
		len = len_unsigned(params, num, 10);
	if (params->precis > len)
		buff_prec = params->precis - len - (1 == params->flag_diese);
	if (params->width > params->precis)
		buff_pad = params->width - buff_prec - len - (params->flag_diese
			&& params->conv != 'p') - 2 * (params->conv == 'p')
		- (params->flag_diese && params->conv != 'o' && params->conv != 'p');
	if (!params->flag_min)
		pad_u(params, &buff_pad, &buff_prec);
	if ((params->flag_diese && num) || params->conv == 'p')
		print_diese(params);
	while (buff_prec-- > 0)
		ft_putchar_params('0', params);
	ft_u_gputnbr(&num, params);
	pad_u(params, &buff_pad, &buff_prec);
	return (0);
}

int				print_u(t_param *params, va_list ap)
{
	if (params->conv == 'p')
		print_unsigned(params, va_arg(ap, unsigned long long));
	else if (params->type == hh || params->type == h || params->type == r)
		print_unsigned(params, va_arg(ap, unsigned int));
	else if (params->type == l)
		print_unsigned(params, va_arg(ap, unsigned long));
	else
		print_unsigned(params, va_arg(ap, unsigned long long));
	return (0);
}
