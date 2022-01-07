/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_revrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:52 by ghanquer          #+#    #+#             */
/*   Updated: 2021/12/15 13:59:30 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rra(t_env *g)
{
	if (!g)
		return (-1);
	t_pile	*ltof;
	t_pile	*tmp;
	
	tmp = &g->pile_a;
	while (tmp->next)
		tmp = tmp->next;
	ltof = tmp;
	tmp = tmp->next;
	ltof->next = g->pile_a;
	g->pile_a = ltof;
	putstr("rra\n");
	return (0);
}

int	rrb(t_env *g)
{
	if (!g)
		return (-1);
	t_pile* ltof;
	t_pile* tmp;

	tmp = &g->pile_b;
	while (tmp->next)
		tmp = tmp->next;
	ltof = tmp;
	tmp = tmp->next;
	ltof->next = g->pile_b;
	g->pile_b = ltof;
	putstr("rrb\n");
	return (0);
}

int	rrr(t_env *g)
{
	rra(g);
	rrb(g);
	putstr("rrr\n");
	return (0);
}