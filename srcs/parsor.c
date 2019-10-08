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

void	parsor(t_env *e)
{
	if (check_numbers(e))
		exit_error(ERR_COUNTING, "doom-nukem: counting error");
	
}
