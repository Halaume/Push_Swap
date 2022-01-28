/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:24:34 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/28 17:09:04 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//void	chose_pos(int *pos)
//{

//}

int	sort(t_env *g)
{
	t_pile	*tmp;
	int		i;
	int		*pos;

	i = 0;
	while (g->info.size_b)
	{
		tmp = g->info.begin_b;
	//	print_pile(*g);
		pos = check_pos(g, tmp->nb);
		if (pos[0] == 0 && pos[1] == 0)
		{
			pa(g);
		}
		else
		{
			while (pos[0] > 0)
			{
				ra(g);
				pos[0] -= 1;
			}
			while (pos[1] > 0)
			{
				rb(g);
				pos[1] -= 1;
			}
			pa(g);
		}
		i++;
	}
	free (pos);
	return (1);
}
