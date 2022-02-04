/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:59:44 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/04 15:23:24 by ghanquer         ###   ########.fr       */
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

int	is_sort(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i + 1] && ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	print_err()
{
	char	*err = "Error";
	int		i;

	i = 0;
	while(err[i])
		write(2, &err[i++], 1);
	exit (-1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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
