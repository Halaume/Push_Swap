/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:30:08 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/27 13:00:33 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	check_pile_b_last(t_env *g, int nb)
{
//	int		check;
	int		i;

	i = 0;
//	check = 0;
	while (g->pile_b != g->info.begin_b && nb != g->pile_b->nb)
	{
		i++;
		g->pile_b = g->pile_b->prev;
	}
	if (i == pile_len(g->pile_b) && nb != g->pile_b->nb)
		return (pile_len(g->pile_b) + 1);
	return (i);
//	if (i <= pile_len(g->pile_b) / 2)
//		check = i;
//	else
//		check = i - pile_len(g->pile_b);
//	return (check);
}

int	check_pile_a_last(t_env *g, int nb)
{
	int		check;
	int		i;

	check = -1;
	i = 0;
	if (nb > g->info.begin_a->nb && nb < g->info.last_a->nb)
		return (0);
	if (nb > g->info.max_a->nb)
	{
		while (g->pile_a != g->info.max_a)
		{
			g->pile_a = g->pile_a->prev;
			i++;
		}
		return (i);
	}
	while (g->pile_a->prev != g->info.last_a)
	{
		i++;
		if (g->pile_a->nb < nb && g->pile_a->prev->nb > nb)
			check = i;
		g->pile_a = g->pile_a->prev;
	}
	if (g->pile_a->nb < nb && g->pile_a->prev->nb > nb)
		check = i + 1;
//	if (check == -1)
//		g->pile_a = g->info.begin_a;
	return (check);
}
