/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_revrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:52 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/21 17:40:26 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rra(t_env *g)
{
	t_pile	*ltof;
	t_pile	*tmp;

	if (!g)
		return (-1);
	tmp = g->pile_a;
	while (tmp->next->next)
		tmp = tmp->next;
	ltof = tmp->next;
	tmp->next = NULL;
	ltof->next = g->pile_a;
	g->pile_a = ltof;
	putstr("rra\n");
	return (0);
}

int	rrb(t_env *g)
{
	t_pile	*ltof;
	t_pile	*tmp;

	if (!g)
		return (-1);
	tmp = g->pile_b;
	while (tmp->next->next)
		tmp = tmp->next;
	ltof = tmp->next;
	tmp->next = NULL;
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
