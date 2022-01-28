/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:58:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/28 13:07:58 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pb(t_env *g)
{
	t_pile	*tmp;
	t_pile	*swap;

	tmp = g->info.begin_b;
	swap = g->info.begin_a;
	if (!(g->pile_a))
		return (-1);
	g->info.begin_b = g->info.begin_a;
	g->info.begin_a = g->info.begin_a->next;
	g->info.begin_a->prev = g->info.last_a;
	g->info.last_a->next = g->info.begin_a;
	g->info.min_a = get_min_a(g);
	g->info.max_a = get_max_a(g);
	if (tmp)
	{
		tmp->prev = swap;
		g->info.begin_b = swap;
		g->info.last_b->next = swap;
		g->info.begin_b->prev = g->info.last_b;
		g->info.begin_b->next = tmp;
	}
	else
	{
		g->info.begin_b = swap;
		g->info.last_b = g->info.begin_b;
		g->info.begin_b->prev = g->info.last_b;
		g->info.last_b->next = g->info.begin_b;
		g->info.begin_b->next = g->info.begin_b;
		g->info.last_b->prev = g->info.begin_b;
	}
	g->info.size_a--;
	g->info.size_b++;
	putstr("pb\n");
	return (0);
}

int	pa(t_env *g)
{
	t_pile	*tmp;
	t_pile	*swap;

	tmp = g->info.begin_a;
	swap = g->info.begin_b;
	if (!(g->pile_a))
		return (-1);
	g->info.begin_a = g->info.begin_b;
	g->info.begin_b = g->info.begin_b->next;
	g->info.begin_b->prev = g->info.last_b;
	g->info.last_b->next = g->info.begin_b;
	if (tmp)
	{
		tmp->prev = swap;
		g->info.begin_a = swap;
		g->info.last_a->next = swap;
		g->info.begin_a->prev = g->info.last_a;
		g->info.begin_a->next = tmp;
	}
	else
	{
		g->info.begin_a = swap;
		g->info.last_a = g->info.begin_a;
		g->info.begin_a->prev = g->info.last_a;
		g->info.last_a->next = g->info.begin_a;
		g->info.begin_a->next = g->info.begin_a;
		g->info.last_a->prev = g->info.begin_a;
	}
	if (g->info.size_b < 1)
	{
		g->info.begin_b = NULL;
		g->info.last_b = NULL;
	}
	g->info.size_a++;
	g->info.size_b--;


/*	if (!(g->pile_b))
		return (-1);
	g->info.begin_a = g->info.begin_b;
	if (pile_len(g->info.begin_b) == 1)
	{
		g->info.begin_b = NULL;
		g->info.last_b = NULL;
	}
	else
	{
		g->info.begin_a->next = g->info.last_a->next;
		g->info.begin_a->prev = g->info.last_a;
		g->info.last_a->next = g->info.begin_a;
		g->info.last_a->prev = g->info.begin_a;

		g->info.last_b = g->info.begin_b;
		g->info.begin_b->prev = g->info.last_b;
		g->info.last_b->next = g->info.begin_b;
		g->info.begin_b = g->info.begin_b->next;
		g->info.begin_b->prev = g->info.begin_b->prev->prev;
		g->info.last_b = g->info.begin_b->prev;
		g->pile_b = ft_lst_delfirst(g->pile_b);
		g->info.begin_b = g->pile_b;
	}*/
	putstr("pa\n");
	return (0);
}
