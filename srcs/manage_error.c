/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:40:05 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/08 15:41:58 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	exit_error(t_env *e, int id, const char *msg)
{
	(void)e;
	(void)id;
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
