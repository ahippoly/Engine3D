/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_gputnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:02:48 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/06 17:19:53 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_u_gputnbr_suite(void *n, char *digit, int base
		, t_param *params)
{
	if (params->type == hh)
		ft_u_putnbr_hh(*((unsigned char*)n), base, digit, params);
	else if (params->type == h)
		ft_u_putnbr_h(*((unsigned short*)n), base, digit, params);
	else if (params->type == r)
		ft_u_putnbr(*((unsigned int*)n), base, digit, params);
	else if (params->type == l)
		ft_u_putnbr_l(*((unsigned long*)n), base, digit, params);
	else
		ft_u_putnbr_ll(*((unsigned long long*)n), base, digit, params);
}

void		ft_u_gputnbr(void *n, t_param *params)
{
	if (params->precis)
	{
		if (params->conv == 'p' || params->conv == 'P')
			print_addr(n, params);
		else if (params->conv == 'o')
			ft_u_gputnbr_suite(n, "01234567", 8, params);
		else if (params->conv == 'x')
			ft_u_gputnbr_suite(n, "0123456789abcdef", 16, params);
		else if (params->conv == 'X')
			ft_u_gputnbr_suite(n, "0123456789ABCDEF", 16, params);
		else
			ft_u_gputnbr_suite(n, "0123456789", 10, params);
	}
	else if (params->conv == 'o' && params->flag_diese)
		ft_u_gputnbr_suite(n, "01234567", 8, params);
}
