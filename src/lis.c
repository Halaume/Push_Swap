/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:05:31 by ghanquer          #+#    #+#             */
/*   Updated: 2022/01/17 16:55:45 by ghanquer         ###   ########.fr       */
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

char	**ft_calloc(size_t nmemb, size_t size, char **argv)
{
	char	**dest;
	int		i;
	int		j;

	j = -1;
	i = -1;
	dest = malloc(sizeof(char **) * nmemb);
	if (nmemb * size > 2147483647)
		return (NULL);
	while (++j < nmemb)
		dest[j] = malloc(sizeof(char) * ft_strlen(argv[j]) + 1);
	if (!dest)
		return (NULL);
	while (++i < nmemb)
		dest[i] = NULL;
	return (dest);
}


char	**lis(int argc, char **argv)
{
	char	**list;
	char	**longestList;
	int		currentMax;
	int		highestCount;
	int		i;
	int		j;
	int		lst_cnt;


	int k = 0;


	lst_cnt = 0;
	i = 0;
	highestCount = 0;
	list = ft_calloc(argc, sizeof(char *), argv);
	if (!list)
		return (NULL);
	longestList = NULL;
	while (i < argc)
	{
		currentMax = -2147483648;
		j = i;
		while (j < argc)
		{
			if((int)ft_atoi(argv[j]) > currentMax)
			{
				list[lst_cnt] = argv[j];
				lst_cnt++;
				currentMax = (int)ft_atoi(argv[j]);
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
			while (list[k])
			{
				longestList[k] = list[k];
				k++;
			}
		}
	}
	if (highestCount == argc - 1)
	{
		printf("LAAAAAAAAAAAAA\n");
		return (NULL);
	}
	printf("LAAAAAAAAAAAAAMAAAAAAA\n");
	free(list);
	return (longestList);

}

int	main(int argc, char **argv)
{
	char **str = lis(argc,argv);
	int i = 0;
	while (str[i])
	{
		printf("La liste : %s\n", str[i]);
		i++;
	}
}
