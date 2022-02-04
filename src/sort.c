/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:24:34 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/04 15:23:31 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	moving_ra_rrb(int *pos, t_env *g)
{
	while (pos[0] > 0)
	{
		ra(g);
		pos[0] -= 1;
	}
	while (pos[3] > 0)
	{
		rrb(g);
		pos[3] -= 1;
	}
}

void	moving_rra_rb(int *pos, t_env *g)
{
	while (pos[2] > 0)
	{
		rra(g);
		pos[2] -= 1;
	}
	while (pos[1] > 0)
	{
		rb(g);
		pos[1] -= 1;
	}
}

void	moving_rr(int *pos, t_env *g)
{
	if (pos[0] > pos[1])
	{
		while (pos[1] > 0)
		{
			rr(g);
			pos[1] -= 1;
			pos[0] -= 1;
		}
		while (pos[0] > 0)
		{
			ra(g);
			pos[0] -= 1;
		}
	}
	else
	{
		while (pos[0] > 0)
		{
			rr(g);
			pos[1] -= 1;
			pos[0] -= 1;
		}
		while (pos[1] > 0)
		{
			rb(g);
			pos[1] -= 1;
		}
	}
}

void	moving_rrr(int *pos, t_env *g)
{
	if (pos[2] > pos[3])
	{
		while (pos[3] > 0)
		{
			rrr(g);
			pos[3] -= 1;
			pos[2] -= 1;
		}
		while (pos[2] > 0)
		{
			rra(g);
			pos[2] -= 1;
		}
	}
	else
	{
		while (pos[2] > 0)
		{
			rrr(g);
			pos[3] -= 1;
			pos[2] -= 1;
		}
		while (pos[3] > 0)
		{
			rrb(g);
			pos[3] -= 1;
		}
	}
}

void	sort(t_env *g)
{
	t_move	*tmp;
	int		*pos;
	t_pile	*stack;

	tmp = NULL;
	while (g->info.size_b)
	{
		stack = g->info.begin_b;
		g->info.max_a = get_max_a(g);
		g->info.min_a = get_min_a(g);
		tmp = free_move(tmp);
		while (stack->next != g->info.begin_b)
		{
			pos = check_pos(g, stack->nb);
			move_add_back(&tmp, move_new(pos));
			stack = stack->next;
		}
		pos = check_pos(g, stack->nb);
		move_add_back(&tmp, move_new(pos));
		while (tmp)
		{
			pos = best_move(pos, tmp->pos);
			tmp = tmp->next;
		}
			chose_position(pos, g);
			pa(g);
	}
	free (pos);
}
