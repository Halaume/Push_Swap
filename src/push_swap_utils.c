/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:32:07 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/04 14:46:36 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long	ft_atoi(char *str)
{
	int			i;
	long long	res;
	int			neg;

	neg = 1;
	i = 0;
	res = 0;
	while (str[i] == '0' || (str[i] < 14 && str[i] > 8) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		if (res > 2147483647 || res < -2147483648)
			return (res);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}

int	pile_len(t_pile *pile)
{
	t_pile	*tmp;
	int		save;
	int		i;

	i = 1;
	if (!pile)
		return (0);
	tmp = pile->next;
	save = pile->nb;
	while (tmp->nb != save)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		i++;
	if (!c[i])
		return (0);
	while (c[i])
	{
		if ((c[i] > '9' || c[i] < '0'))
			return (0);
		i++;
	}
	return (1);
}

t_pile	*get_min_a(t_env *g)
{
	int		currmin;
	t_pile	*min;

	currmin = 2147483647;
	g->pile_a = g->info.begin_a;
	min = g->pile_a;
	while (g->pile_a != g->info.last_a)
	{
		if (g->pile_a->nb < currmin)
		{
			currmin = g->pile_a->nb;
			min = g->pile_a;
		}
		g->pile_a = g->pile_a->next;
	}
	if (g->pile_a->nb < currmin)
	{
		currmin = g->pile_a->nb;
		min = g->pile_a;
	}
	return (min);
}

t_pile	*get_max_a(t_env *g)
{
	int		currmax;
	t_pile	*max;

	max = g->info.begin_a;
	currmax = -2147483648;
	g->pile_a = g->info.begin_a;
	while (g->pile_a != g->info.last_a)
	{
		if (g->pile_a->nb > currmax)
		{
			currmax = g->pile_a->nb;
			max = g->pile_a;
		}
		g->pile_a = g->pile_a->next;
	}
	if (g->pile_a->nb > currmax)
	{
		currmax = g->pile_a->nb;
		max = g->pile_a;
	}
	return (max);
}
