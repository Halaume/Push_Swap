/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:52:38 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/12 10:32:19 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int argc, char **argv)
{	
	int		i;
	int		nb;
	int		j;
	char	*nbs;
	t_pile	*tmp;
	t_env	g;

	(void)argc;
	i = 0;
	while (argv[1][i])
	{
		nbs = NULL;
		j = 0;
		while (ft_isdigit(argv[1][i]))
		{
			nbs[j] = argv[1][i];
			i++;
			j++;
		}
		if (nbs)
		{
			nb = ft_atoi(nbs);
			tmp = ft_lstnew(nb);
			ft_lstadd_front(&g.pile_a, tmp);
		}
		i++;
	}
	return (0);
}
