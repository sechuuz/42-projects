/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:58:44 by sechavez          #+#    #+#             */
/*   Updated: 2025/11/18 19:11:37 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	start;
	size_t	wrds;

	i = 0;
	wrds = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && start == 0)
		{
			start = 1;
			wrds++;
		}
		if (str[i] == c && start == 1)
			start = 0;
		i++;
	}
	return (wrds);
}

static void	free_arr(char **arr, int i)
{
	while (i-- > 0)
		free(arr[i]);
	free(arr);
}

static char	**fill_arr(char **strarr, char const *str, char c, size_t i)
{
	size_t	arr;
	size_t	start;

	start = 0;
	arr = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > start)
		{
			strarr[arr] = ft_substr(str, start, i - start);
			if (!strarr[arr])
			{
				free_arr(strarr, arr);
				return (0);
			}
			arr++;
		}
	}
	strarr[arr] = 0;
	return (strarr);
}

char	**ft_split(char const *str, char c)
{
	char	**strarr;

	if (!str)
		return (0);
	strarr = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!strarr)
		return (0);
	return (fill_arr(strarr, str, c, 0));
}
