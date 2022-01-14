/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:52:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/14 12:28:37 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

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

int	main(int argc, char **argv)
{	
	int		i;
	int		nb;
	t_env	g;

	g.pile_a = NULL;
	g.pile_b = NULL;
	i = 1;
	while (i < argc)
	{
		while (argv[i])
		{
			nb = ft_atoi(argv[i]);
			i++;
			ft_lstadd_back(&g.pile_a, ft_lstnew(nb));
		}
		i++;
	}
//	rra(&g);
	print_pile(g);
	return (0);
}
