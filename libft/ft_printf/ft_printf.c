/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:35 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/11 11:13:57 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	int		num;
	va_list	ap;
	t_param	params;

	i = 0;
	num = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			params = parsor(format, i, ap);
			print_variable(&params, ap);
			i += params.size_opt + 1 * (params.conv != '0' || params.percent);
			num += params.num;
		}
		else
		{
			ft_putchar_params(format[i], NULL);
			num++;
			i++;
		}
	}
	return (num);
}
