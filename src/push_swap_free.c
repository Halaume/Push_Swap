/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:26:23 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/17 18:23:25 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_pile_a(t_env *g)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp2 = g->info.begin_a;
	tmp = tmp2->next;
	tmp2 = NULL;
	g->info.last_a = NULL;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		tmp2 = NULL;
		free(tmp2);
	}
	free(tmp);
}

void	free_pile_b(t_env *g)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = g->info.begin_b;
	tmp2 = tmp;
	tmp = tmp->next;
	free(tmp2);
	g->info.last_b = NULL;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}

void	fun_free(t_env *g)
{
	if (g->info.begin_a)
		free_pile_a(g);
	if (g->info.begin_b)
		free_pile_b(g);
}
