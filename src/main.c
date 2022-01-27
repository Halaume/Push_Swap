/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:52:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/27 17:28:39 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_pile(t_env g)
{
	printf("PILE_A\n");
	g.pile_a = g.info.begin_a;
	while(g.pile_a != g.info.last_a)
	{
		printf("%d\t->\t%d\n", g.pile_a->nb,g.pile_a->is_in_lis);
		g.pile_a = g.pile_a->next;
	}
		printf("%d\t->\t%d\n", g.info.last_a->nb,g.info.last_a->is_in_lis);
	printf("\nPILE_B\n");
	g.pile_b = g.info.begin_b;
	while(g.pile_b != g.info.last_b)
	{
		printf("%d\t->\t%d\n", g.pile_b->nb,g.pile_b->is_in_lis);
		g.pile_b = g.pile_b->next;
	}
		printf("%d\t->\t%d\n", g.info.last_b->nb,g.info.last_b->is_in_lis);
	g.pile_a = g.info.begin_a;
	g.pile_b = g.info.begin_b;
}

void	print_info(t_env g)
{
	printf("begin a -> %d,last_a -> %d, min_a -> %d\n", g.info.begin_a->nb, g.info.last_a->nb, g.info.min_a->nb);
	printf("begin a prev -> %d,last_a next -> %d, min_a -> %d\n\n\n", g.info.begin_a->prev->nb, g.info.last_a->next->nb, g.info.min_a->nb);
//	if (g.info.begin_b != NULL)
//	printf("begin b -> %d,last_b -> %d, min_b -> %d\n", g.info.begin_b->nb, g.info.last_b->nb, g.info.min_b->nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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

void	check_lis(t_env *g)
{
	t_pile	*tmp;
	t_pile	*last;
	int		i;

	tmp = NULL;
	i = -1;
	tmp = g->info.begin_a;
	last = g->info.last_a;
	while (tmp != last)
	{
		tmp = g->info.begin_a;
		if (tmp->is_in_lis < 0)
		{
			printf("oui%d\n",tmp->nb);
			pb(g);
		}
		else
			ra(g);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb;
	int		min;
	t_env	g;

	if (argc <= 2)
		return (0);
	min = 2147483647;
	if (!checkarg(argc, argv))
		return (print_err());
	if (is_sort(argc, argv) == 0)
		return (0);
	i = 1;
	g.pile_a = NULL;
	g.pile_b = NULL;
	g.info = info_init(g);
	while (i < argc)
	{
		while (argv[i])
		{
			if (!ft_isdigit(argv[i]))
			{
				return (print_err());
			}
			if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
				return (print_err());
			nb = (int)ft_atoi(argv[i]);
			if (nb < min)
				min = nb;
			i++;
			ft_lstadd_back(&g.pile_a, ft_lstnew(nb, 0));
		}
		i++;
	}
	g.info.begin_a = g.pile_a;
	while (g.pile_a->nb != nb)
	{
		if (g.pile_a->nb == min)
			g.info.min_a = g.pile_a;
		g.pile_a = g.pile_a->next;
	}
	g.info.last_a = g.pile_a;
	g.info.last_a->next = g.info.begin_a;
	g.info.begin_a->prev = g.info.last_a;
	if (argc == 3)
	{
		sa(&g);
		return (0);
	}
	get_lis(&g);
//	print_pile(g);
//	print_info(g);
	print_info(g);
	check_lis(&g);
	print_pile(g);
	printf("begin b -> %d,last_b -> %d\n", g.info.begin_b->nb, g.info.last_b->nb);
	printf("begin b prev -> %d,last_b next -> %d\n", g.info.begin_b->prev->nb, g.info.last_b->next->nb);
//	sort(&g);
	print_info(g);
	return (0);
}
