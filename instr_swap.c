/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:14 by ghanquer          #+#    #+#             */
/*   Updated: 2021/12/15 13:59:31 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sa(t_env g)
{
	if (!g.pile_a)
		return (-1);
	t_pile	*tmp;

	tmp = g.pile_a;
	g.pile_a = g.pile_a->next;
	g.pile_a->next = tmp;
	putstr("sa\n");
	return (0);
}

int	sb(t_env *g)
{
	if (g->pile_b->nb == NULL)
		return (-1);
	t_pile	*tmp;

	tmp = g->pile_b;
	g->pile_b = g->pile_b->next;
	g->pile_b->next = tmp;
	putstr("sb\n");
	return (0);
}

int	ss(t_env *g)
{
//	sa(g);
	sb(g);
	putstr("ss\n");
	return (0);
}