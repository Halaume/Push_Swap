/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:15:49 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/17 11:22:15 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	moving_rr2(int *pos, t_env *g)
{
	while (pos[0] > 0)
	{
		rr(g);
		pos[1] -= 1;
		pos[0] -= 1;
	}
	while (pos[1] > 0)
	{
		rb(g);
		pos[1] -= 1;
	}
}

void	moving_rr(int *pos, t_env *g)
{
	if (pos[0] > pos[1])
	{
		while (pos[1] > 0)
		{
			rr(g);
			pos[1] -= 1;
			pos[0] -= 1;
		}
		while (pos[0] > 0)
		{
			ra(g);
			pos[0] -= 1;
		}
	}
	else
		moving_rr2(pos, g);
}

void	moving_rrr2(int *pos, t_env *g)
{
	while (pos[2] > 0)
	{
		rrr(g);
		pos[3] -= 1;
		pos[2] -= 1;
	}
	while (pos[3] > 0)
	{
		rrb(g);
		pos[3] -= 1;
	}
}

void	moving_rrr(int *pos, t_env *g)
{
	if (pos[2] > pos[3])
	{
		while (pos[3] > 0)
		{
			rrr(g);
			pos[3] -= 1;
			pos[2] -= 1;
		}
		while (pos[2] > 0)
		{
			rra(g);
			pos[2] -= 1;
		}
	}
	else
		moving_rrr2(pos, g);
}
