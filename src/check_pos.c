/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:12:28 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/21 15:27:05 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pile_len(t_pile *pile)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = pile;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	best_pos(int *pos1, int *pos2)
{
	if ((pos1[0] >= 0 && pos1[1] >= 0) && (pos2[0] >= 0 && pos2[1] >= 0))
	{
		if (pos1[0] - pos1[1] < pos2[0] - pos2[1])
			return (1);
		else
			return (2);
	}
	else if ((pos1[0] < 0 && pos1[1] < 0) && (pos2[0] < 0 && pos2[1] < 0))
	{
		if (pos1[0] + pos1[1] < pos2[0] + pos2[1])
			return (1);
		else
			return (2);
	}
	return (1);
}

int	check_pile_b(t_pile *pile_b, int nb)
{
	int		check;
	t_pile	*tmp;
	int		i;

	i = 0;
	check = 0;
	tmp = pile_b;
	while (tmp->next && nb != tmp->nb)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == pile_len(pile_b) && nb != tmp->nb)
		return (pile_len(pile_b) + 1);
	if (i <= pile_len(pile_b) / 2)
		check = i;
	else
		check = i - pile_len(pile_b);
	return (check);
}

int	check_pile_a(t_pile *pile_a, int nb)
{
	int		check;
	t_pile	*tmp;
	int		i;

	check = 0;
	i = 0;
	tmp = pile_a;
	while (tmp->next)
	{
		if (tmp->nb < nb && tmp->next && tmp->next->nb > nb)
			check = i;
		tmp = tmp->next;
		i++;
	}
	if (pile_a->nb < nb && tmp->nb < nb)
		check = -1;
	else if (pile_a->nb > nb && tmp->nb > nb)
		check = 0;
	tmp = pile_a;
	return (check);
}

int	*check_pos(t_env *g, int nb)
{
	int	*pos;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (NULL);
	pos[0] = check_pile_a(g->pile_a, nb);
	pos[1] = check_pile_b(g->pile_b, nb);
	return (pos);
}
