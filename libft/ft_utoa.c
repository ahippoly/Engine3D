/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:48:52 by msiesse           #+#    #+#             */
/*   Updated: 2019/01/06 16:22:03 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_usize(unsigned int n)
{
	int	size;

	size = 1;
	while ((n = n / 10) != 0)
		size++;
	return (size);
}

char		*ft_utoa(unsigned int n)
{
	char			*nbr;
	size_t			i;
	size_t			len;

	i = 0;
	len = get_usize(n);
	if (!(nbr = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		nbr[i] = n / ft_pow(10, len - i - 1) + 48;
		n %= ft_pow(10, len - i - 1);
		i++;
	}
	return (nbr);
}
