/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:00:35 by msiesse           #+#    #+#             */
/*   Updated: 2018/12/03 13:53:55 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(const char *str)
{
	int			i;
	int			signe;
	long long	num;

	signe = 1;
	i = 0;
	num = 0;
	while ((str[i] <= 13 && str[i] >= 8) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		signe = 44 - str[i];
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	return (num * signe);
}
