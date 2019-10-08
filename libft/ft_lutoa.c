/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:53:41 by msiesse           #+#    #+#             */
/*   Updated: 2019/01/03 18:28:33 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_lusize(unsigned long n)
{
	int	size;

	size = 1;
	while ((n = n / 10) != 0)
		size++;
	return (size);
}

char		*ft_lutoa(unsigned long n)
{
	char			*nbr;
	size_t			i;
	size_t			len;

	i = 0;
	len = get_lusize(n);
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
