/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:12:28 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/17 17:04:59 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_pile_b(t_env *g, int nb)
{
	int		i;

	i = 0;
	g->pile_b = g->info.begin_b;
	if (g->pile_b->next == g->pile_b)
		return (0);
	while (g->pile_b != g->info.last_b && nb != g->pile_b->nb)
	{
		i++;
		g->pile_b = g->pile_b->next;
	}
	if (i == pile_len(g->pile_b) && nb != g->pile_b->nb)
		return (pile_len(g->pile_b) + 1);
	return (i);
}

int	check_pile_a_2(t_env *g, int nb, int i)
{
	while (g->pile_a->next != g->info.begin_a)
	{
		i++;
		if (g->pile_a->nb > nb && g->pile_a->prev->nb < nb)
		{
			if (g->pile_a == g->info.begin_a)
				return (0);
			return (i);
		}
		g->pile_a = g->pile_a->next;
	}
	if (g->pile_a->nb > nb && g->pile_a->prev->nb < nb)
		return (i + 1);
	return (-1);
}

int	check_pile_a(t_env *g, int nb)
{
	int		i;

	i = -1;
	g->pile_a = g->info.begin_a;
	if (nb > g->info.max_a->nb)
	{
		i++;
		if (g->info.begin_a == g->info.min_a)
			return (0);
		while (g->pile_a != g->info.min_a)
		{
			g->pile_a = g->pile_a->next;
			i++;
		}
		return (i);
	}
	return (check_pile_a_2(g, nb, i));
}

int	*check_pos(t_env *g, int nb, int *pos)
{
	pos = malloc(sizeof(int) * 4);
	if (!pos)
		return (NULL);
	pos[0] = check_pile_a(g, nb);
	pos[1] = check_pile_b(g, nb);
	pos[2] = check_pile_a_last(g, nb);
	pos[3] = check_pile_b_last(g, nb);
	return (pos);
}
