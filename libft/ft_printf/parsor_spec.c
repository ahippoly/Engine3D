/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:38:36 by msiesse           #+#    #+#             */
/*   Updated: 2019/01/06 16:23:23 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		parsor_flag(const char *format, int i, t_param *params)
{
	while (format[i] && is_flag(format[i]))
	{
		if (format[i] == '-')
			params->flag_min = 1;
		else if (format[i] == '+')
			params->flag_plus = 1;
		else if (format[i] == '0')
			params->flag_0 = 1;
		else if (format[i] == '#')
			params->flag_diese = 1;
		else
			params->flag_space = 1;
		params->size_opt++;
		i++;
	}
	return (i);
}

int		parsor_precis(const char *format, int i, t_param *params, va_list ap)
{
	int			j;
	int			wildcard;
	const char	*cp;

	j = 0;
	wildcard = 0;
	cp = &format[i + 1];
	while (format[i + j + 1] && ((format[i + j + 1] >= '0'
			&& format[i + j + 1] <= '9') || format[i + j + 1] == '*'))
	{
		if (format[i + j + 1] == '*')
			wildcard++;
		j++;
	}
	while (wildcard)
	{
		cp = ft_strchr(cp, '*');
		wildcard--;
		params->precis = va_arg(ap, int);
		cp++;
	}
	if (*cp >= '0' && *cp <= '9')
		params->precis = ft_atoi(cp);
	params->size_opt += j + 1;
	return (i + j + 1);
}

int		parsor_type(const char *format, int i, t_param *params)
{
	if (format[i++] == 'h' && format[i] == 'h' && params->size_opt++
			&& params->type < l)
		params->type = hh;
	else if (format[--i] == 'h' && params->type < l)
		params->type = h;
	else if (format[i++] == 'l' && format[i] == 'l' && params->size_opt++)
		params->type = ll;
	else if (format[--i] == 'l')
		params->type = l;
	else if (format[i] == 'L')
		params->type = L;
	params->size_opt++;
	return (i + 1);
}

int		parsor_pad(const char *format, int i, t_param *params, va_list ap)
{
	int			j;
	int			wildcard;
	const char	*cp;

	j = 0;
	cp = &format[i];
	wildcard = 0;
	while (format[i + j] && ((format[i + j] >= '0' && format[i + j] <= '9')
		|| format[i + j] == '*'))
	{
		if (format[i + j] == '*')
			wildcard++;
		j++;
	}
	while (wildcard)
	{
		cp = ft_strchr(cp, '*');
		wildcard--;
		params->width = va_arg(ap, int);
		cp++;
	}
	if (*cp >= '0' && *cp <= '9')
		params->width = ft_atoi(cp);
	params->size_opt += j;
	return (i + j);
}
