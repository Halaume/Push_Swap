/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:01:39 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/01 18:35:10 by ghanquer         ###   ########.fr       */
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

void	free_move(t_move *move)
{
	t_move	*tmp;

	tmp = move;
	while (tmp)
	{
		tmp = tmp->next;
		free(move->pos);
		free(move);
		move = tmp;
	}
}

int	*best_move(int *pos1, int *pos2)
{
	int	nb_move1;
	int	nb_move2;

	if (nb_move1 >= nb_move2)
		return (pos2);
	else
		return (pos1);
}
