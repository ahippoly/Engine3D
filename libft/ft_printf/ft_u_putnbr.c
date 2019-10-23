/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:19:07 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/11 11:15:51 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_u_putnbr(unsigned int n, int base, char *digit, t_param *params)
{
	if (n < (unsigned int)base)
		ft_putchar_params(digit[n], params);
	else
	{
		ft_u_putnbr(n / base, base, digit, params);
		ft_putchar_params(digit[n % base], params);
	}
}

void	ft_u_putnbr_h(unsigned short n, int base, char *digit, t_param *params)
{
	if (n < (unsigned short)base)
		ft_putchar_params(digit[n], params);
	else
	{
		ft_u_putnbr_h(n / base, base, digit, params);
		ft_putchar_params(digit[n % base], params);
	}
}

void	ft_u_putnbr_hh(unsigned char n, int base, char *digit, t_param *params)
{
	if (n < (unsigned char)base)
		ft_putchar_params(digit[n], params);
	else
	{
		ft_u_putnbr_hh(n / base, base, digit, params);
		ft_putchar_params(digit[n % base], params);
	}
}

void	ft_u_putnbr_l(unsigned long n, int base, char *digit, t_param *params)
{
	if (n < (unsigned long)base)
		ft_putchar_params(digit[n], params);
	else
	{
		ft_u_putnbr_l(n / base, base, digit, params);
		ft_putchar_params(digit[n % base], params);
	}
}

void	ft_u_putnbr_ll(unsigned long long n, int base, char *digit
		, t_param *params)
{
	if (n < (unsigned long long)base)
		ft_putchar_params(digit[n], params);
	else
	{
		ft_u_putnbr_ll(n / base, base, digit, params);
		ft_putchar_params(digit[n % base], params);
	}
}
