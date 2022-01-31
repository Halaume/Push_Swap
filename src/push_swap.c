/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:59:44 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/31 14:02:04 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	set_min_first(t_env *g)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = g->info.begin_a;
	if (g->info.min_a != g->info.begin_a)
	{
		while (tmp != g->info.min_a)
		{
			tmp = tmp->next;
			i++;
		}
		if (i < g->info.size_a / 2)
		{
			while (g->info.min_a != g->info.begin_a)
			{
				ra(g);
				tmp = g->info.begin_a;
			}
		}
		else
		{
			while (g->info.min_a != g->info.begin_a)
			{
				rra(g);
				tmp = g->info.begin_a;
			}
		}
	}
}
int	push_swap()
{
	return (0);
}
