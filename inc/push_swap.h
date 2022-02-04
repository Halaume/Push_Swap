/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:00:16 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/04 15:23:27 by ghanquer         ###   ########.fr       */
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

typedef struct s_move {
	int				*pos;
	struct s_move	*next;
}	t_move;

typedef struct s_info {
	t_pile	*begin_a;
	t_pile	*last_a;
	t_pile	*min_a;
	int		size_a;
	t_pile	*max_a;
	t_pile	*begin_b;
	t_pile	*last_b;
	int		size_b;
}	t_info;

typedef struct s_env {
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_info	info;
}	t_env;

//		BASIC FUNCTION

void			putstr(char *s);
int				is_sort(int argc, char **argv);
int				ft_strcmp(char *s1, char *s2);
int				ft_isdigit(char *c);
long long		ft_atoi(char *str);

//		SORT

void			sort(t_env *g);
int				*check_pos(t_env *g, int nb);
void			chose_position(int *pos, t_env *g);
void			moving_rr(int *pos, t_env *g);
void			moving_rrr(int *pos, t_env *g);
void			moving_ra_rrb(int *pos, t_env *g);
void			moving_rra_rb(int *pos, t_env *g);

//		CHECKING ARG

int				print_err(void);
int				check_pile_a_last(t_env *g, int nb);
int				check_pile_b_last(t_env *g, int nb);

//		LST_MOVE

int				*best_move(int *pos1, int *pos2);
t_move			*move_new(int *nb);
void			move_add_back(t_move **move, t_move *new);
void			move_add_front(t_move **alst, t_move *new);
t_move			*free_move(t_move *move);

//		PRINTING

void			print_info(t_env g);
void			print_pile(t_env g);

//		LST_PILE / INFO

char			**lis(int argc, char **argv);
int				pile_len(t_pile *pile);
void			ft_lstadd_front(t_pile **alst, t_pile *new);
void			ft_lstadd_back(t_pile **alst, t_pile *new);
void			ft_lstadd_back_circle(t_pile **alst, t_pile *new);
t_pile			*ft_lstnew(int content, int is_lis);
t_pile			*ft_lst_delfirst(t_pile *pile);
t_info			info_init(t_env g);
t_pile			*get_min_a(t_env *g);
t_pile			*get_max_a(t_env *g);
void			get_lis(t_env *g);
void			set_min_first(t_env *g);

//		OPERATIONS

int				sa(t_env *g);
int				sb(t_env *g);
int				ss(t_env *g);
int				pa(t_env *g);
int				pb(t_env *g);
int				ra(t_env *g);
int				rb(t_env *g);
int				rr(t_env *g);
int				rra(t_env *g);
int				rrb(t_env *g);
int				rrr(t_env *g);

#endif
