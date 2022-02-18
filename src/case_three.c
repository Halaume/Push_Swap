/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:34:46 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/18 17:40:10 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sort(t_env(*g))
{
	t_pile	*tmp;

	tmp = g->info.min_a;
	g->info.min_a = get_min_a(g);
	g->info.max_a = get_max_a(g);
	tmp = g->info.min_a;
	while (tmp->next != g->info.min_a)
	{
		if (tmp->next->nb < tmp->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	case_three(t_env *g)
{
	if (g->info.size_a != 3)
		return (-1);
	if (check_sort(g) == 1 && g->info.begin_a == g->info.min_a)
		return (0);
	if (check_sort(g) == 0)
		sa(g);
	if (!g->info.begin_b)
	{
		set_min_first(g);
		fun_free(g);
		exit(1);
	}
	return (1);
}
