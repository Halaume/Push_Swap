/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:30:08 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/02 14:48:53 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_pile_b_last(t_env *g, int nb)
{
	int		i;

	i = 0;
	if (g->pile_b->next == g->pile_b)
		return (0);
	if (nb == g->info.last_b->nb)
		return (1);
	else if (nb == g->info.begin_b->nb)
		return (0);
	while (g->pile_b != g->info.begin_b && nb != g->pile_b->nb)
	{
		i++;
		g->pile_b = g->pile_b->prev;
	}
	if (i == pile_len(g->pile_b) && nb != g->pile_b->nb)
		return (pile_len(g->pile_b) + 1);
	return (i);
}

int	check_pile_a_last(t_env *g, int nb)
{
	int		check;
	int		i;

	check = -1;
	i = 0;
	if (nb > g->info.max_a->nb)
	{
		while (g->pile_a != g->info.min_a)
		{
			g->pile_a = g->pile_a->prev;
			i++;
		}
		return (i);
	}
	while (g->pile_a->prev != g->info.last_a)
	{
		i++;
		if (g->pile_a->nb > nb && g->pile_a->prev->nb < nb)
			check = i;
		g->pile_a = g->pile_a->prev;
	}
	if (g->pile_a->nb > nb && g->pile_a->prev->nb < nb)
		check = i + 1;
	return (check);
}
