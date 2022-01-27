/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:00:16 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/27 13:00:31 by ghanquer         ###   ########.fr       */
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
	struct s_pile	*prev;
}	t_pile;

typedef struct s_info {
	t_pile	*begin_a;
	t_pile	*last_a;
	t_pile	*min_a;
	t_pile	*max_a;
	t_pile	*begin_b;
	t_pile	*last_b;
	int		disorder;
}	t_info;

typedef struct s_env {
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_info	info;
}	t_env;

int				print_err();
int				pile_len(t_pile *pile);
int				*check_pos(t_env *g, int nb);
int				check_pile_a_last(t_env *g, int nb);
int				check_pile_b_last(t_env *g, int nb);
void			putstr(char *s);
int				ft_isdigit(char *c);
long long		ft_atoi(char *str);
void			ft_lstadd_front(t_pile **alst, t_pile *new);
void			ft_lstadd_back(t_pile **alst, t_pile *new);
void			ft_lstadd_back_circle(t_pile **alst, t_pile *new);
t_pile			*ft_lstnew(int content, int is_lis);
t_pile			*ft_lst_delfirst(t_pile *pile);
t_info			info_init(t_env g);
char			**lis(int argc, char **argv);
int				sort(t_env *g);
int				*best_pos(int *pos1, int *pos2);
t_pile			*get_min_a(t_env *g);
t_pile			*get_max_a(t_env *g);
void			get_lis(t_env *g);


void			print_info(t_env g);
void			print_pile(t_env g);

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
