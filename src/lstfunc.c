/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:59:56 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/18 17:25:24 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pile	*ft_lstnew(int content, int is_lis)
{
	t_pile	*tmp;

	tmp = malloc(sizeof(t_pile));
	if (tmp)
	{
		tmp->nb = content;
		tmp->is_in_lis = is_lis;
		tmp->next = NULL;
	}
	return (tmp);
}

void	ft_lstadd_back(t_pile **alst, t_pile *new)
{
	t_pile	*tmp;

	if (alst && new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = *alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	ft_lstadd_front(t_pile **alst, t_pile *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_pile	*ft_lst_delfirst(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile->next;;
	free(pile);
	return (tmp);
}