/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:59:56 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/12 10:22:59 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_pile	*ft_lstnew(int content)
{
	t_pile	*tmp;

	tmp = malloc(sizeof(t_pile));
	if (tmp)
	{
		tmp->nb = content;
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

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	neg;

	neg = 1;
	i = 0;
	res = 0;
	while (str[i] == '0' || (str[i] < 14 && str[i] > 8) || str [i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
