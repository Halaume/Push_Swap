/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_revrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:52 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/04 13:16:38 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rra(t_env *g)
{
	if (!g->pile_a)
		return (-1);
	g->info.last_a = g->info.last_a->prev;
	g->info.begin_a = g->info.begin_a->prev;
	putstr("rra\n");
	return (0);
}

int	rrb(t_env *g)
{
	if (!g->pile_b)
		return (-1);
	g->info.last_b = g->info.last_b->prev;
	g->info.begin_b = g->info.begin_b->prev;
	putstr("rrb\n");
	return (0);
}

int	rrr(t_env *g)
{
	if (!g->pile_a)
		return (-1);
	if (!g->pile_b)
		return (-1);
	g->info.last_a = g->info.last_a->prev;
	g->info.begin_a = g->info.begin_a->prev;
	g->info.last_b = g->info.last_b->prev;
	g->info.begin_b = g->info.begin_b->prev;
	putstr("rrr\n");
	return (0);
}
