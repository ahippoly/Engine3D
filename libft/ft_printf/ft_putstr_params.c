/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:08:38 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:20:35 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_putstr_params(const char *s, t_param *params)
{
	int len;

	len = ft_strlen(s);
	write(1, s, len);
	if (params)
		params->num += len;
}
