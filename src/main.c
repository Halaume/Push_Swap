/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:52:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/18 17:25:24 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_pile(t_env g)
{
	printf("PILE_A\n\n");
	while(g.pile_a)
	{
		printf("%d\n", g.pile_a->nb);
		g.pile_a = g.pile_a->next;
	}
	printf("PILE_B\n\n");
	while(g.pile_b)
	{
		printf("%d\n", g.pile_b->nb);
		g.pile_b = g.pile_b->next;
	}
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
	return (-1);
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
			j++;
		}
		i++;
	}
	return (1);
}

void	check_lis(t_env *g, int argc, char **argv)
{
	char	**lis_str;
	t_pile	*tmp;
	int		i;

	tmp = NULL;
	i = -1;
	lis_str = lis(argc, argv);
	while (lis_str[++i])
	{
		tmp = g->pile_a;
		while (tmp->next)
		{
			if (tmp->nb == (int)ft_atoi(lis_str[i]))
				tmp->is_in_lis = 1;
			tmp = tmp->next;
		}
	}
	i = 0;
	while(i < argc)
	{
		i++;
		if (g->pile_a->is_in_lis == 0)
			pa(g);
		else if (i < argc)
			ra(g);
	}
	tmp = g->pile_a;
	while (tmp->next)
		tmp = tmp->next;
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb;
	t_env	g;

	if (argc <= 2)
		return (0);
	if (!checkarg(argc, argv))
		return (print_err());
	i = 1;
	g.pile_a = NULL;
	g.pile_b = NULL;
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
			i++;
			ft_lstadd_back(&g.pile_a, ft_lstnew(nb, 0));
		}
		i++;
	}
	check_lis(&g, argc, argv);
	print_pile(g);
	return (0);
}
