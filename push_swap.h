/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:00:16 by ghanquer          #+#    #+#             */
/*   Updated: 2021/12/15 14:01:18 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_pile {
	int		nb;
	struct s_pile *next;
}	t_pile;

typedef struct s_env {
	t_pile *pile_a;
	t_pile *pile_b;
}	t_env;

void	putstr(char* s);

int		sa(t_env g);
int		sb(t_env* g);
int		ss(t_env* g);
int		pa(t_env* g);
int		pb(t_env* g);
int		ra(t_env* g);
int		ra(t_env* g);
int		ra(t_env* g);
int		rra(t_env* g);
int		rrb(t_env* g);
int		rrr(t_env* g);




#endif
