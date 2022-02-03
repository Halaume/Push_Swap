/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:24:34 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/03 18:39:09 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*void	chose_pos_rrr_next(int *pos, t_env *g)
{
	if (pos[0] + pos[1] >= pos[2] + pos[3] && pos[2] >= pos[3] && pos[0] > 0)
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
		pa(g);
	}
}

void	chose_pos_rrr(int *pos, t_env *g)
{
	if (pos[0] + pos[1] >= pos[2] + pos[3] && pos[2] <= pos[3] && pos[0] > 0)
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
			pos[0] -= 1;
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
			pos[0] -= 1;
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
}*/

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
		pos[3] -=1;
	}
}

void	moving_rra_rb(int *pos, t_env *g)
{
	while (pos[2] > 0)
	{
		rra(g);
		pos[2] -=1;
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

int	sort(t_env *g)
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
		int *firstpos = check_pos(g, stack->nb);
		int *lastpos = NULL;
		while (stack->next != g->info.begin_b)
		{
//			print_pile(*g);
			pos = check_pos(g, stack->nb);
//			printf("nb : %d\nint * : \n%d \n%d \n%d \n%d\n", stack->nb, pos[0], pos[1], pos[2], pos[3]);
			move_add_back(&tmp, move_new(pos));
			stack = stack->next;
		}
		lastpos = check_pos(g, stack->nb);
		pos = check_pos(g, stack->nb);
		move_add_back(&tmp, move_new(pos));
		print_pile(*g);
		printf("lastnb %d, first nb %d\n", stack->nb, stack->next->nb);
		printf("-------------------FIRST---------------------\n");
		printf("Pos1 : %d\n", firstpos[0]);
		printf("Pos2 : %d\n", firstpos[1]);
		printf("Pos3 : %d\n", firstpos[2]);
		printf("Pos4 : %d\n", firstpos[3]);
		printf("--------------------LAST--------------------\n");
		printf("Pos1 : %d\n", lastpos[0]);
		printf("Pos2 : %d\n", lastpos[1]);
		printf("Pos3 : %d\n", lastpos[2]);
		printf("Pos4 : %d\n", lastpos[3]);
		while (tmp)
		{
			pos = best_move(pos, tmp->pos);
			tmp = tmp->next;
		}
//		print_pile(*g);
//		printf("nb : %d\nint * : \n%d \n%d \n%d \n%d\n", stack->nb, pos[0], pos[1], pos[2], pos[3]);
//		if (pos[0] == 0 && pos[1] == 0)
//		{
//			pa(g);
//		}
//		else
//		{
			chose_position(pos, g);
			pa(g);
//		}
	}
	free (pos);
	return (1);
}
