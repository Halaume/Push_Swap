/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:52:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/17 19:10:54 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	checkarg(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			if (!ft_isdigit(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			print_err_nofree();
		i++;
	}
	if (argc <= 2)
		exit(0);
	if (!checkarg(argc, argv))
		print_err_nofree();
	if (is_sort(argc, argv) == 0)
		exit(0);
}

void	check_lis(t_env *g)
{
	t_pile	*tmp;
	t_pile	*last;
	int		i;

	tmp = NULL;
	i = 0;
	tmp = g->info.begin_a;
	last = g->info.last_a;
	while (tmp != last)
	{
		i++;
		tmp = g->info.begin_a;
		if (tmp->is_in_lis < 0)
			pb(g);
		else
			ra(g);
	}
}

void	fill_pile(int argc, char **argv, t_env *g)
{
	int	i;
	int	nb;

	i = 1;
	while (i < argc)
	{
		while (argv[i])
		{
			if (!ft_isdigit(argv[i]))
				print_err(g);
			nb = (int)ft_atoi(argv[i]);
			i++;
			g->info.size_a++;
			ft_lstadd_back(&g->pile_a, ft_lstnew(nb, 0));
		}
		i++;
	}
	g->info.begin_a = g->pile_a;
	while (g->pile_a->nb != nb)
		g->pile_a = g->pile_a->next;
	g->info.last_a = g->pile_a;
	g->info.last_a->next = g->info.begin_a;
	g->info.begin_a->prev = g->info.last_a;
	g->info.min_a = get_min_a(g);
	g->info.max_a = get_max_a(g);
}

int	main(int argc, char **argv)
{
	t_env	g;

	check_error(argc, argv);
	g.pile_a = NULL;
	g.pile_b = NULL;
	g.info = info_init(g);
	fill_pile(argc, argv, &g);
	if (argc == 3)
	{
		ra(&g);
		free(g.pile_a->next);
		free(g.pile_a);
		return (0);
	}
	get_lis(&g);
	check_lis(&g);
	sort(&g);
	g.info.min_a = get_min_a(&g);
	set_min_first(&g);
	fun_free(&g);
	return (0);
}
