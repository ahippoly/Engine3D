/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:13:06 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/24 17:50:24 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*str;

	if (!(s1 && s2))
		return (NULL);
	i = -1;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(*str) * (len1 + len2 + 1))))
		return (NULL);
	while (++i < len1)
		str[i] = s1[i];
	while (i < (len1 + len2))
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
