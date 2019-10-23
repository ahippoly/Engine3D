/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:18:31 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/06 17:11:25 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static t_param	init_param(void)
{
	t_param	params;

	params.flag_min = 0;
	params.flag_plus = 0;
	params.flag_0 = 0;
	params.flag_diese = 0;
	params.flag_space = 0;
	params.precis = -1;
	params.width = -1;
	params.type = r;
	params.size_opt = 1;
	params.percent = 0;
	params.signe = 0;
	params.num = 0;
	params.conv = '0';
	return (params);
}

static int		is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
			|| c == 'c' || c == 's' || c == 'p' || c == 'f')
		return (1);
	return (0);
}

int				is_flag(char c)
{
	if (c == '-' || c == '+' || c == '0' || c == '#' || c == ' ')
		return (1);
	return (0);
}

static int		modif_diese(t_param *params)
{
	if (params->conv == 'u')
		params->flag_diese = 0;
	else if ((params->conv == 'x' || params->conv == 'X')
			&& params->flag_diese)
		params->flag_diese = 2;
	return (0);
}

t_param			parsor(const char *format, int i, va_list ap)
{
	t_param	params;

	params = init_param();
	i++;
	while (format[i] && !is_conv(format[i]) && is_ok(format[i]))
	{
		if (is_flag(format[i]))
			i = parsor_flag(format, i, &params);
		else if (format[i] == '%')
		{
			params.percent = 1;
			break ;
		}
		else if (format[i] == '.' && params.precis == -1)
			i = parsor_precis(format, i, &params, ap);
		else if (!(format[i] >= '0' && format[i] <= '9') && format[i] != '*')
			i = parsor_type(format, i, &params);
		if ((format[i] == '*' || (format[i] >= '0' && format[i] <= '9'))
				&& params.width == -1)
			i = parsor_pad(format, i, &params, ap);
	}
	if (format[i] && format[i] != '%' && is_conv(format[i]))
		params.conv = format[i];
	modif_diese(&params);
	return (params);
}
