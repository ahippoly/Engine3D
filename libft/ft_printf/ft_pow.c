/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:10:44 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/03 14:42:54 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long		ft_pow(unsigned long long a, unsigned int power)
{
	unsigned long long	mem;

	mem = a;
	if (power == 0)
		return (1);
	while (--power)
		a *= mem;
	return (a);
}
