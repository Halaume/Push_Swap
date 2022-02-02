/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:01:39 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/02 12:43:57 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_move	*move_new(int *nb)
{
	t_move	*tmp;

	tmp = malloc(sizeof(t_move));
	if (!tmp)
		return (NULL);
	tmp->pos = nb;
	tmp->next = NULL;
	return (tmp);
}

void	move_add_back(t_move **move, t_move *new)
{
	t_move	*tmp;

	if (move && new)
	{
		tmp = *move;
		if (*move == NULL)
			*move = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	move_add_front(t_move **alst, t_move *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_move	*free_move(t_move *move)
{
	t_move	*tmp;

	if (!move)
		return (NULL);
	tmp = move;
	while (tmp)
	{
		tmp = tmp->next;
		free(move->pos);
		free(move);
		move = tmp;
	}
	return (NULL);
}

int	*best_move(int *pos1, int *pos2)
{
	int	nb_move1;
	int	nb_move2;

	if (!pos1)
		return (pos2);
	nb_move1 = pos1[0] + pos1[1];
	nb_move2 = pos2[0] + pos2[1];
	if (nb_move1 > pos1[2] + pos1[3])
		nb_move1 = pos1[2] + pos1[3];
	if (nb_move2 > pos2[2] + pos2[3])
		nb_move2 = pos2[2] + pos2[3];
	if (nb_move1 > pos1[0] + pos1[3])
		nb_move1 = pos1[0] + pos1[3];
	if (nb_move2 > pos2[0] + pos2[3])
		nb_move2 = pos2[0] + pos2[3];
	if (nb_move1 > pos1[1] + pos1[2])
		nb_move1 = pos1[1] + pos1[2];
	if (nb_move2 > pos2[1] + pos2[2])
		nb_move2 = pos2[1] + pos2[2];
	if (nb_move1 >= nb_move2)
		return (pos2);
	else
		return (pos1);
}
