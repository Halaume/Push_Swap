/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:21:14 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/27 15:00:54 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rem_double(t_env *g)
{
	t_pile	*current;
	t_pile	*tmp;
	int		i;

	i = pile_len(g->info.begin_a);
	current = g->info.min_a;
	tmp = g->info.min_a;
	while (tmp != g->info.min_a->prev)
	{
		current = g->info.min_a;
		while (current != g->info.min_a->prev)
		{
			if (current != tmp && current->is_in_lis != -1 && current->is_in_lis == tmp->is_in_lis)
			{
				g->info.disorder++;
				current->is_in_lis = -1;
			}
			current = current->next;
		}
		if (current != tmp && current->is_in_lis != -1 && current->is_in_lis == tmp->is_in_lis)
		{
			g->info.disorder++;
			current->is_in_lis = -1;
		}
		tmp = tmp->next;
	}
}

void	get_move(t_env *g)
{
	t_pile *current;
	t_pile *tmp;

	tmp = g->info.min_a;
	current = tmp->next;
	while (current != tmp)
	{
		if (current->is_in_lis == tmp->is_in_lis - 1 
				&& current->nb > tmp->nb)
		{
			tmp = current;
		}
		else if (current->is_in_lis <= tmp->is_in_lis && current->is_in_lis != -1)
		{
			g->info.disorder++;
			current->is_in_lis = -1;
		}
		current = current->next;
	}
	current = current->next;
}

void	get_lis(t_env *g)
{
	t_pile *current;
	t_pile *tmp;

	current = g->info.min_a->prev;
	current->is_in_lis = 1;
	while (current != g->info.min_a)
	{
		current = current->prev;
		current->is_in_lis = 1;
		tmp = current->next;
		while (tmp != g->info.min_a)
		{
			if (current->nb < tmp->nb && current->is_in_lis < tmp->is_in_lis + 1)
				current->is_in_lis = tmp->is_in_lis + 1;
			tmp = tmp->next;
		}
	}
	get_move(g);
	rem_double(g);
}
