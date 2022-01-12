/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:58:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/12 17:38:43 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	pa(t_env *g)
{
	if (!(g->pile_a))
		return (-1);
	g->pile_b->next = g->pile_b;
	g->pile_b = g->pile_a;
	g->pile_a = g->pile_a->next;
	putstr("pa\n");
	return (0);
}

int	pb(t_env *g)
{
	if (!(g->pile_b))
		return (-1);
	g->pile_a->next = g->pile_a;
	g->pile_a = g->pile_b;
	g->pile_b = g->pile_b->next;
	putstr("pb\n");
	return (0);
}
