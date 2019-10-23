/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:47:26 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/06 12:50:16 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_addr(void *addr, t_param *params)
{
	ft_u_putnbr_ll(*(unsigned long long*)addr, 16, "0123456789abcdef", params);
}
