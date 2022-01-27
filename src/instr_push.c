/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:58:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/27 15:33:01 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pb(t_env *g)
{
	t_pile	*tmp;

	tmp = g->info.begin_b;
	if (!(g->pile_a))
		return (-1);
	g->info.begin_b = g->info.begin_a;
	ft_lstadd_back_circle(&g->info.begin_b, ft_lstnew(g->info.begin_a->nb, g->info.begin_a->is_in_lis));
	g->info.begin_a = g->info.begin_a->next;
	g->info.begin_a->prev = g->info.last_a;
	g->info.last_a->next = g->info.begin_a;
//	g->pile_a = ft_lst_delfirst(g->pile_a);
	g->info.min_a = get_min_a(g);
	if (tmp)
	{
		tmp = g->info.begin_b;
		g->info.begin_b->next = g->info.last_b->next;
		g->info.begin_b->prev = g->info.last_b;
		g->info.last_b->next = g->info.begin_b;
	}
	else
	{
		g->info.last_b = g->info.begin_b;
		g->info.begin_b->prev = g->info.last_b;
		g->info.last_b->next = g->info.begin_b;
		g->info.begin_b->next = g->info.begin_b;
		g->info.last_b->prev = g->info.begin_b;
	}
	putstr("pb\n");
	return (0);
}

int	pa(t_env *g)
{
	if (!(g->pile_b))
		return (-1);
	g->info.begin_a = g->info.begin_b;
	ft_lstadd_back_circle(&g->info.begin_a, ft_lstnew(g->info.begin_b->nb, g->pile_b->is_in_lis));
	if (pile_len(g->info.begin_b) == 1)
	{
		g->info.begin_b = NULL;
		g->info.last_b = NULL;
	}
	g->info.last_b = g->info.begin_b;
	g->info.begin_b->prev = g->info.last_b;
	g->info.last_b->next = g->info.begin_b;
	g->info.begin_b = g->info.begin_b->next;
	g->info.begin_b->prev = g->info.begin_b->prev->prev;
	g->info.last_b = g->info.begin_b->prev;
	g->pile_b = ft_lst_delfirst(g->pile_b);
	g->info.begin_b = g->pile_b;
	putstr("pa\n");
	return (0);
}
