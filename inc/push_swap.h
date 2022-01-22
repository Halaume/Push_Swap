/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:00:16 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/22 13:29:27 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_pile {
	int				nb;
	int				is_in_lis;
	struct s_pile	*next;
}	t_pile;

typedef struct s_env {
	t_pile	*pile_a;
	t_pile	*pile_b;
}	t_env;

int				pile_len(t_pile *pile);
int				*check_pos(t_env *g, int nb);
void			putstr(char *s);
int				ft_isdigit(char *c);
long long		ft_atoi(char *str);
void			ft_lstadd_front(t_pile **alst, t_pile *new);
void			ft_lstadd_back(t_pile **alst, t_pile *new);
t_pile			*ft_lstnew(int content, int is_lis);
t_pile			*ft_lst_delfirst(t_pile *pile);
char			**lis(int argc, char **argv);
int				sort(t_env *g);
int				*best_pos(int *pos1, int *pos2);

int				sa(t_env *g);
int				sb(t_env *g);
int				ss(t_env *g);
int				pa(t_env *g);
int				pb(t_env *g);
int				ra(t_env *g);
int				ra(t_env *g);
int				ra(t_env *g);
int				rra(t_env *g);
int				rrb(t_env *g);
int				rrr(t_env *g);

#endif
