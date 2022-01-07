/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:59:11 by ghanquer          #+#    #+#             */
/*   Updated: 2021/12/15 13:59:31 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ra(t_env *g)
{
	if (!g)
		return (-1);
	t_pile	*ftol;
	t_pile	*tmp;

	ftol = g->pile_a;
	g->pile_a = g->pile_a->next;
	tmp = &g->pile_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ftol;
	putstr("ra\n");
	return (0);
}

int rb(t_env *g)
{
	if (!g)
		return (-1);
	t_pile	*ftol;
	t_pile	*tmp;

	ftol = g->pile_b;
	g->pile_b = g->pile_b->next;
	tmp = &g->pile_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ftol;
	putstr("rb\n");

	return (0);
}

int rr(t_env *g)
{
	ra(g);
	rb(g);
	putstr("rr\n");
	return (0);
}