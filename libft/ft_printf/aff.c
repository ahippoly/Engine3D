/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:42:19 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/06 14:53:50 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		size_number(long long n, int base)
{
	int				size;
	unsigned long	un;

	size = 0;
	if (n < 0)
		un = -n;
	else
		un = n;
	while (un /= base)
		size++;
	size++;
	return (size);
}

int		size_u_number(unsigned long long n, int base)
{
	int				size;

	size = 0;
	while (n /= base)
		size++;
	size++;
	return (size);
}

void	print_variable(t_param *params, va_list ap)
{
	if (params->conv == 'c' || params->percent)
		print_char(params, ap);
	else if (params->conv == 'd' || params->conv == 'i')
		print_dec(params, ap);
	else if (params->conv == 'o' || params->conv == 'x'
			|| params->conv == 'X' || params->conv == 'u'
			|| params->conv == 'p')
		print_u(params, ap);
	else if (params->conv == 'f')
		print_float(params, ap);
	else if (params->conv == 's')
		print_string(params, ap);
}
