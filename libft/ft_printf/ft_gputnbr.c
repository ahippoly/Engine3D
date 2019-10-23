/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:44:58 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:20:05 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_gputnbr(void *n, t_param *params)
{
	if (params->precis || *(long long*)n != 0)
	{
		if (params->type == hh)
			ft_putnbr_params_hh(*((char*)n), params);
		else if (params->type == h)
			ft_putnbr_params_h(*((short*)n), params);
		else if (params->type == r)
			ft_putnbr_params(*((int*)n), params);
		else if (params->type == l)
			ft_putnbr_params_l(*((long*)n), params);
		else
			ft_putnbr_params_ll(*((long long*)n), params);
	}
}
