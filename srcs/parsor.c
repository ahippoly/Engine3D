/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:10:34 by msiesse           #+#    #+#             */
/*   Updated: 2019/10/08 15:42:01 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	init_parsor(t_parsor *parsor)
{
	ft_bzero(parsor->count, sizeof(int) * 4);
	ft_bzero(parsor->check_n, sizeof(t_bool) * 4);
	parsor->total_check = 0;
	parsor->what_check = 0;
}

void	doom_parsor(t_env *e)
{
	init_parsor(&e->parsor);
	if (check_numbers(e))
		exit_error(e, ERR_COUNTING, "doom-nukem: counting error");
}
