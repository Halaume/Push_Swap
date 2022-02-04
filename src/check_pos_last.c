/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:30:08 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/04 13:16:37 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_pile_b_last(t_env *g, int nb)
{
	int		i;

	i = 1;
	g->pile_b = g->info.last_b;
	if (g->pile_b->next == g->pile_b)
		return (0);
	if (nb == g->info.last_b->nb)
		return (1);
	else if (nb == g->info.begin_b->nb)
		return (0);
	while  (nb != g->pile_b->nb)
		g->pile_b = g->pile_b->prev;
	while (g->pile_b != g->info.begin_b)
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
	int		i;

	i = 0;
	g->pile_a = g->info.begin_a;
	if (nb > g->info.max_a->nb)
	{
//		i++;
		if (g->info.begin_a == g->info.min_a)
			return (0);
		while (g->pile_a != g->info.min_a)
		{
			g->pile_a = g->pile_a->prev;
			i++;
		}
		return (i);
	}
	while (g->pile_a != g->info.begin_a->next)
	{
		if (g->pile_a->nb > nb && g->pile_a->prev->nb < nb)
		{
			if(g->pile_a == g->info.begin_a)
				return (0);
			return (i);
		}
		i++;
		g->pile_a = g->pile_a->prev;
	}
	if (g->pile_a->nb > nb && g->pile_a->prev->nb < nb)
		 return (i + 1);
	return (-1);
}
