/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:54:44 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/11 11:18:20 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_params(int n, t_param *params)
{
	unsigned int	new;

	new = (n > 0) ? n : -n;
	if (new < 10)
		ft_putchar_params(new + 48, params);
	else
	{
		ft_putnbr_params(new / 10, params);
		ft_putchar_params(new % 10 + 48, params);
	}
}

void	ft_putnbr_params_hh(char n, t_param *params)
{
	unsigned char	new;

	new = (n > 0) ? n : -n;
	if (new < 10)
		ft_putchar_params(new + 48, params);
	else
	{
		ft_putnbr_params_hh(new / 10, params);
		ft_putchar_params(new % 10 + 48, params);
	}
}

void	ft_putnbr_params_h(short n, t_param *params)
{
	unsigned short	new;

	new = (n > 0) ? n : -n;
	if (new < 10)
		ft_putchar_params(new + 48, params);
	else
	{
		ft_putnbr_params_h(new / 10, params);
		ft_putchar_params(new % 10 + 48, params);
	}
}

void	ft_putnbr_params_l(long n, t_param *params)
{
	unsigned long	new;

	new = (n > 0) ? n : -n;
	if (new < 10)
		ft_putchar_params(new + 48, params);
	else
	{
		ft_putnbr_params_l(new / 10, params);
		ft_putchar_params(new % 10 + 48, params);
	}
}

void	ft_putnbr_params_ll(long long n, t_param *params)
{
	unsigned long long	new;

	new = (n > 0) ? n : -n;
	if (new < 10)
		ft_putchar_params(new + 48, params);
	else
	{
		ft_putnbr_params_ll(new / 10, params);
		ft_putchar_params(new % 10 + 48, params);
	}
}
