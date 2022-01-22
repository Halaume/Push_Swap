/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:32:07 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/22 13:29:24 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long	ft_atoi(char *str)
{
	int			i;
	long long	res;
	int			neg;

	neg = 1;
	i = 0;
	res = 0;
	while (str[i] == '0' || (str[i] < 14 && str[i] > 8) || str[i] == ' ')
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
		if (res > 2147483647 || res < -2147483648)
			return (res);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}

int	pile_len(t_pile *pile)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = pile;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (c[i])
	{
		if (!(c[i] > 47 && c[i] < 58))
			return (0);
		i++;
	}
	return (1);
}
