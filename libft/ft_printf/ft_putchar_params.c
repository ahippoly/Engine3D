/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:05:31 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:06:18 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_putchar_params(char c, t_param *params)
{
	write(1, &c, 1);
	if (params)
		params->num++;
}
