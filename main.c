/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:52:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/12 17:38:42 by ghanquer         ###   ########.fr       */
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
	int		j;
	char	*nbs;
	t_pile	*tmp;
	t_env	g;

	g.pile_a = NULL;
	g.pile_b = NULL;
	(void)argc;
	i = 0;
	while (argv[1][i])
	{
		nbs = malloc(sizeof(char) * 1 + 1);
		if (!nbs)
			return (-1);
		j = 0;
		while (ft_isdigit(argv[1][i]) && argv[1][i] != '\0')
		{
			nbs[j] = argv[1][i];
			i++;
			j++;
		}
		nbs[j] = '\0';
		if (nbs[0])
		{
			nb = ft_atoi(nbs);
			tmp = ft_lstnew(nb);
			ft_lstadd_front(&g.pile_a, tmp);
		}
		free(nbs);
		i++;
	}
	sa(&g);
	pb(&g);
	print_pile(g);
	return (0);
}
