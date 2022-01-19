/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:05:31 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/19 18:02:22 by ghanquer         ###   ########.fr       */
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
	if (nmemb * size > 2147483647)
		return (NULL);
	while (++j < nmemb)
		dest[j - 1] = malloc(sizeof(char) * ft_strlen(argv[j]) + 1);
	if (!dest)
		return (NULL);
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
	if (nmemb * size > 2147483647)
		return (NULL);
	while (++j < nmemb)
		dest[j] = malloc(sizeof(char) * ft_strlen(argv[j]) + 1);
	if (!dest)
		return (NULL);
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

/*int	is_min(int argc, char **argv, int min)
{
	int	i;

	i = 0;
	while((int)ft_atoi(argv[i]) != min)
		i++;
	while (i < argc)
	{
		if ((int)ft_atoi(argv[i]) < min)
			min = (int)ft_atoi(argv[i]);
		i++;
	}
	printf("%d\n\n",min);
	return (min);
}*/

char	**lis(int argc, char **argv)
{
	char	**list;
	char	**longestList;
	int		currentMax;
	int		highestCount;
	int		i;
	int		j;
	int		lst_cnt;
	int		k;

	k = 0;
	lst_cnt = 0;
	i = 0;
	highestCount = 0;
	list = ft_calloc_base(argc, sizeof(char *), argv);
	if (!list)
		return (NULL);
	longestList = NULL;
	while (i < argc)
	{
		currentMax = min(argc, argv, 2147483647);
		j = i + 1;
		lst_cnt = 0;
		while (j < argc)
		{
			if(ft_atoi(argv[j]) > currentMax)
			{
				if (j + 1 != argc && ft_atoi(argv[j + 1]) > currentMax && ft_atoi(argv[j]) > ft_atoi(argv[j + 1]))
				{
					list[lst_cnt] = argv[j + 1];
					lst_cnt++;
					currentMax = (int)ft_atoi(argv[j + 1]);
				}
				else
				{
					list[lst_cnt] = argv[j];
					lst_cnt++;
					currentMax = (int)ft_atoi(argv[j]);
				}
			}
			j++;
		}
		i++;
		if (highestCount < lst_cnt)
		{
			highestCount = lst_cnt;
			if (longestList != NULL)
				free(longestList);
			longestList = ft_calloc(lst_cnt, sizeof(char *), list);
			if (!longestList)
				return (NULL);
			while (k < lst_cnt)
			{
				longestList[k] = list[k];
				k++;
			}
		}
	}
	free(list);
	if (k == argc - 1)
		return (NULL);
	return (longestList);
}

/*int	main(int argc, char **argv)
{
	char **str = lis(argc,argv);
	int i = -1;
	if (str)
	{
		while (str[++i])
		{
			printf("La liste : %s\n", str[i]);
		}
	}
}*/
