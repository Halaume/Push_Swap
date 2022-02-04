/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:58:22 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/04 13:16:39 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	positioning(int *pos, t_env *g)
{
	int best_move;
	int	nb_move;

	best_move = 0;
	nb_move = pos[0] + pos[1];
	if (nb_move > pos[2] + pos[3])
	{
		nb_move = pos[2] + pos[3];
		best_move = 1;
	}
	if (nb_move > pos[0] + pos[3])
	{
		nb_move = pos[0] + pos[3];
		best_move = 2;
	}
	if (nb_move > pos[1] + pos[2])
	{
		nb_move = pos[1] + pos[2];
		best_move = 3;
	}
	return (best_move);
}

void	chose_position(int *pos, t_env *g)
{
	int	i;

	i = positioning(pos, g);
	if (i == 0)
		moving_rr(pos, g);
	else if (i == 1)
		moving_rrr(pos, g);
	else if (i == 2)
		moving_ra_rrb(pos, g);
	else
		moving_rra_rb(pos, g);
}
