/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:59:11 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/26 16:21:34 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ra(t_env *g)
{
	if (!g->pile_a)
		return (-1);
	g->info.begin_a = g->info.begin_a->next;
	g->info.last_a = g->info.last_a->next;
	putstr("ra\n");
	return (0);
}

int	rb(t_env *g)
{
	if (!g->pile_b)
		return (-1);
	g->info.begin_b = g->info.begin_b->next;
	g->info.last_b = g->info.last_b->next;
	putstr("rb\n");
	return (0);
}

int	rr(t_env *g)
{
	ra(g);
	rb(g);
	putstr("rr\n");
	return (0);
}
