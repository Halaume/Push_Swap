/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:12:28 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/28 13:07:57 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	big_pos(int pos1, int pos2)
{
	if (pos1 > pos2)
		return (pos1);
	else
		return (pos2);
}

int	*best_pos(int *pos1, int *pos2)
{
	if ((pos1[0] >= 0 && pos1[1] >= 0) && (pos2[0] >= 0 && pos2[1] >= 0))
	{
		if (big_pos(pos1[0], pos1[1]) < big_pos(pos2[0], pos2[1]))
			return (pos1);
		else
			return (pos2);
	}
	else if ((pos1[0] < 0 && pos1[1] < 0) && (pos2[0] < 0 && pos2[1] < 0))
	{
		if (big_pos(pos1[0], pos1[1]) > big_pos(pos2[0], pos2[1]))
			return (pos1);
		else
			return (pos2);
	}
//	else
//		if (pos1[0] + pos2[0] > pos2[0] + pos2[1])
//			return (0);
	return (NULL);
}

int	check_pile_b(t_env *g, int nb)
{
//	int		check;
	int		i;

	i = 0;
//	check = 0;
	while (g->pile_b != g->info.last_b && nb != g->pile_b->nb)
	{
		i++;
		g->pile_b = g->pile_b->next;
	}
	if (i == pile_len(g->pile_b) && nb != g->pile_b->nb)
		return (pile_len(g->pile_b) + 1);
	return (i);
//	if (i <= pile_len(g->pile_b) / 2)
//		check = i;
//	else
//		check = i - pile_len(g->pile_b);
//	return (check);
}

int	check_pile_a(t_env *g, int nb)
{
	int		check;
	int		i;

	check = -1;
	i = 0;
	if ((nb < g->info.begin_a->nb && nb > g->info.last_a->nb) || (nb > g->info.begin_a->nb && nb < g->info.last_a->nb))
		return (0);
	if (nb > g->info.max_a->nb)
	{
		while (g->pile_a != g->info.max_a)
		{
			g->pile_a = g->pile_a->next;
			i++;
		}
		return (i);
	}
	while (g->pile_a->next != g->info.begin_a)
	{
		i++;
		if (g->pile_a->nb < nb && g->pile_a->next->nb > nb)
			check = i;
		g->pile_a = g->pile_a->next;
	}
	if (g->pile_a->nb < nb && g->pile_a->next->nb > nb)
		check = i + 1;
//	if (check == -1)
//		g->pile_a = g->info.begin_a;
	return (check);
}

int	*check_pos(t_env *g, int nb)
{
	int	*pos;

	pos = malloc(sizeof(int) * 4);
	if (!pos)
		return (NULL);
	g->pile_a = g->info.begin_a;
	g->pile_b = g->info.begin_b;
	pos[0] = check_pile_a(g, nb);
	pos[1] = check_pile_b(g, nb);
	g->pile_a = g->info.last_a;
	g->pile_b = g->info.last_b;
	pos[2] = check_pile_a_last(g, nb);
	pos[3] = check_pile_b_last(g, nb);
//	printf("\nPos1 : %d\n", pos[0]);
//	printf("Pos2 : %d\n", pos[1]);
//	printf("Pos3 : %d\n", pos[2]);
//	printf("Pos4 : %d\n\n", pos[3]);
	return (pos);
}
