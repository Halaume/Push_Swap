/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:59:56 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/27 15:33:02 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_info	info_init(t_env g)
{
	g.info.begin_a = g.pile_a;
	g.info.last_a = NULL;
	g.info.min_a = NULL;
	g.info.begin_b = g.pile_b;
	g.info.last_b = NULL;
	return (g.info);
}

t_pile	*ft_lstnew(int content, int is_lis)
{
	t_pile	*tmp;

	tmp = malloc(sizeof(t_pile));
	if (!tmp)
		return (NULL);
	tmp->nb = content;
	tmp->is_in_lis = is_lis;
	tmp->next = NULL;
	tmp->prev = NULL;
 return (tmp);
}

void	ft_lstadd_back(t_pile **alst, t_pile *new)
{
	t_pile	*tmp;

	if (alst && new)
	{
		tmp = *alst;
		if (*alst == NULL)
			*alst = new;
		else
		{
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
			new->prev = tmp;
		}
	}
}

void	ft_lstadd_back_circle(t_pile **alst, t_pile *new)
{
	t_pile	*tmp;
	t_pile	*start;

	start = *alst;
	if (alst && new)
	{
		tmp = *alst;
		if (*alst == NULL)
			*alst = new;
		else
		{
			while (tmp->next != start)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
			new->prev = tmp;
			new->next = start;
		}
	}
}

void	ft_lstadd_front(t_pile **alst, t_pile *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
		new->next->prev = new;
	}
}

t_pile	*ft_lst_delfirst(t_pile *pile)
{
	t_pile	*tmp;

	tmp = NULL;
	if (pile->next)
		tmp = pile->next;
	free(pile);
	return (tmp);
}
