/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:58:22 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/02 17:14:59 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	positioning(int *pos, t_env *g)
{
	int best_move;
	int	nb_move;

	best_move = 0;
	nb_move = pos[0] + pos[1];
	if (nb_move > pos[2] + pos[3])
	{
		nb_move = pos[2] + pos[3];
	}
	if (nb_move > pos[0] + pos[3])
	{
		nb_move = pos[0] + pos[3];
	}
	if (nb_move > pos[1] + pos[2])
	{
		nb_move = pos[1] + pos[2];
	}
	if (best_move = 0)
		fun_r;
}
