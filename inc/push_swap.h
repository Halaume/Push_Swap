/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:00:16 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/12 10:45:29 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_pile {
	int				nb;
	struct s_pile	*next;
}	t_pile;

typedef struct s_env {
	t_pile	*pile_a;
	t_pile	*pile_b;
}	t_env;

void	putstr(char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_lstadd_front(t_pile **alst, t_pile *new);
void	ft_lstadd_back(t_pile **alst, t_pile *new);
t_pile	*ft_lstnew(int content);

int		sa(t_env g);
int		sb(t_env *g);
int		ss(t_env *g);
int		pa(t_env *g);
int		pb(t_env *g);
int		ra(t_env *g);
int		ra(t_env *g);
int		ra(t_env *g);
int		rra(t_env *g);
int		rrb(t_env *g);
int		rrr(t_env *g);

#endif
