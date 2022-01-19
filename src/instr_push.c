/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:58:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/19 11:55:03 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pb(t_env *g)
{
	if (!(g->pile_a))
		return (-1);
	ft_lstadd_back(&g->pile_b, ft_lstnew(g->pile_a->nb, g->pile_a->is_in_lis));
	g->pile_a = ft_lst_delfirst(g->pile_a);
	putstr("pb\n");
	return (0);
}

int	pa(t_env *g)
{
	if (!(g->pile_b))
		return (-1);
	ft_lstadd_back(&g->pile_a, ft_lstnew(g->pile_b->nb, g->pile_b->is_in_lis));
	g->pile_b = ft_lst_delfirst(g->pile_b);
	putstr("pa\n");
	return (0);
}
