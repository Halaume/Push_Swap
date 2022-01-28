/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:14 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/28 13:08:00 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sa(t_env *g)
{
	t_pile	*tmp;

	if (!g->info.begin_a)
		return (-1);
	tmp = g->info.begin_a;
	g->info.begin_a = g->info.begin_a->next;
	tmp->next = g->info.begin_a->next;
	g->info.begin_a->next->prev = tmp;
	g->info.begin_a->next = tmp;
	g->info.begin_a->next->prev = g->info.begin_a;
	g->info.begin_a->prev = g->info.last_a;
	g->info.last_a->next = g->info.begin_a;
	putstr("sa\n");
	return (0);
}

int	sb(t_env *g)
{
	t_pile	*tmp;

	if (!g->info.begin_b)
		return (-1);
	tmp = g->info.begin_b;
	g->info.begin_b = g->info.begin_b->next;
	tmp->next = g->info.begin_b->next;
	g->info.begin_b->next->prev = tmp;
	g->info.begin_b->next = tmp;
	g->info.begin_b->next->prev = g->info.begin_b;
	g->info.begin_b->prev = g->info.last_b;
	g->info.last_b->next = g->info.begin_b;
	putstr("sb\n");
	return (0);
}

int	ss(t_env *g)
{
	sa(g);
	sb(g);
	putstr("ss\n");
	return (0);
}
