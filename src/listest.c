/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:05:31 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/26 16:20:19 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
	{}
	return (i);
}

char	**ft_calloc_base(size_t nmemb, size_t size, char **argv)
{
	char	**dest;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	dest = malloc(sizeof(char *) * nmemb);
	if (!dest)
		return (NULL);
	if (nmemb * size > 2147483647)
		return (NULL);
	while (++j < nmemb)
		dest[j - 1] = malloc(sizeof(char) * ft_strlen(argv[j]) + 1);
	while (++i < nmemb)
		dest[i] = NULL;
	return (dest);
}

char	**ft_calloc(size_t nmemb, size_t size, char **argv)
{
	char	**dest;
	size_t	i;
	size_t	j;

	j = -1;
	i = -1;
	dest = malloc(sizeof(char *) * (nmemb + 1));
	if (!dest)
		return (NULL);
	if (nmemb * size > 2147483647)
		return (NULL);
	while (++j < nmemb)
	{
		dest[j] = malloc(sizeof(char) * ft_strlen(argv[j]) + 1);
		if (!dest[j])
		{
			//			j = -1;
			//			while (dest[++j])
			//				free(dest[j]);		PAS SUR
			free(dest);
			return (NULL);
		}
	}
	while (++i <= nmemb)
		dest[i] = NULL;
	return (dest);
}

int	min(int argc, char **argv, int min)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if ((int)ft_atoi(argv[i]) < min)
			min = (int)ft_atoi(argv[i]);
	}
	return (min);
}

char	**lis(int argc, char **argv)
{
	char	**list;
	char	**longestlist;
	int		currentmax;
	int		highestcount;
	int		i;
	int		j;
	int		lst_cnt;
	int		k;
	int		min;

	k = 0;
	lst_cnt = 0;
	i = 1;
	highestcount = 0;
	min = 2147483647;
	list = ft_calloc_base(argc, sizeof(char *), argv);
	if (!list)
		return (NULL);
	longestlist = NULL;
	while (i < argc)
	{
		if ((int)ft_atoi(argv[i]) < min)
		{
			j = i;
			min = ft_atoi(argv[j]);
		}
		i++;
	}
	currentmax = min;
	list[lst_cnt] = argv[j];
	lst_cnt++;
	printf("%d\n", min);
	i = 0;
	while (i < argc)
	{
		if (j == argc)
			j = 1;
		else
			j++;
		while (ft_atoi(argv[j]) != min)
		{
			if (ft_atoi(argv[j]) > currentmax)
			{
				if (j + 1 != argc && ft_atoi(argv[j + 1]) > currentmax && ft_atoi(argv[j]) > ft_atoi(argv[j + 1]))
				{
				}
				else if (j + 1 == argc - 1)
				{
					if (ft_atoi(argv[1]) > currentmax && ft_atoi(argv[j]) > ft_atoi(argv[0]))
					{
					}
				}
				else
				{
					list[lst_cnt] = argv[j];
					lst_cnt++;
					currentmax = (int)ft_atoi(argv[j]);
				}
			}
			j++;
			if (j == argc)
				j = 1;
		}
		j++;
		i++;
		if (highestcount < lst_cnt)
		{
			highestcount = lst_cnt;
			if (longestlist != NULL)
				free(longestlist);
			longestlist = ft_calloc(lst_cnt, sizeof(char *), list);
			if (!longestlist)
			{
				free(list);
				return (NULL);
			}
			while (k < lst_cnt)
			{
				longestlist[k] = list[k];
				k++;
			}
		}
	}
	free(list);
	if (k == argc - 1)
	{
		free(longestlist);
		return (NULL);
	}
	int w=-1;
	if (longestlist)
	{
		while (longestlist[++w])
			printf("La liste : %s\n", longestlist[w]);
	}
	return (longestlist);
}
