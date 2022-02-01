/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:24:34 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/01 18:35:08 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	chose_pos_rrr_next(int *pos, t_env *g)
{
	if (pos[0] + pos[1] > pos[2] + pos[3] && pos[2] >= pos[3])
	{
		while (pos[3] > 0)
		{
			rrr(g);
			pos[3] -= 1;
		}
		while (pos[2] > 0)
		{
			rra(g);
			pos[2] -= 1;
		}
		pa(g);
	}
}

void	chose_pos_rrr(int *pos, t_env *g)
{
	if (pos[0] + pos[1] > pos[2] + pos[3] && pos[2] <= pos[3])
	{
		while (pos[2] > 0)
		{
			rrr(g);
			pos[2] -= 1;
		}
		while (pos[3] > 0)
		{
			rrb(g);
			pos[3] -= 1;
		}
		pa(g);
	}
	else
		chose_pos_rrr_next(pos,g);
}

void	chose_pos_next(int *pos, t_env *g)
{
	if (pos[0] + pos[1] <= pos[2] + pos[3] && pos[0] <= pos[1])
	{
		while (pos[0] > 0)
		{
			rr(g);
			pos[1] -= 1;
		}
		while (pos[1] > 0)
		{
			rb(g);
			pos[1] -= 1;
		}
		pa(g);
	}
	else
		chose_pos_rrr(pos,g);
}

void	chose_pos(int *pos, t_env *g)
{
	if (pos[0] + pos[1] <= pos[2] + pos[3] && pos[0] >= pos[1])
	{
		while (pos[1] > 0)
		{
			rr(g);
			pos[1] -= 1;
		}
		while (pos[0] > 0)
		{
			ra(g);
			pos[0] -= 1;
		}
		pa(g);
	}
	else
		chose_pos_next(pos, g);
}

int	sort(t_env *g)
{
	t_move	*tmp;
	int		*pos;
	int		i;

	tmp = NULL;
	while (g->info.size_b)
	{
		i = g->info.size_b;
		while (i)
		{
			i--;
			pos = check_pos(g, g->info.begin_b->nb);
			move_add_back(&tmp, move_new(pos));
		}
		while (tmp)
		{
			pos = best_move(tmp->pos, tmp->next->pos);
			tmp = tmp->next;
		}
		g->info.max_a = get_max_a(g);
		if (pos[0] == 0 && pos[1] == 0)
		{
			pa(g);
		}
		else
			chose_pos(pos, g);
	}
	free (pos);
	return (1);
}
