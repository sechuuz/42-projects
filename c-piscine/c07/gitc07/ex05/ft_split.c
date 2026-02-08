/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:15:59 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/14 16:16:01 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i++])
			return (1);
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	start;
	int	wrds;

	i = 0;
	wrds = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset) && start == 0)
		{
			start = 1;
			wrds++;
		}
		if (is_sep(str[i], charset) && start == 1)
			start = 0;
		i++;
	}
	return (wrds);
}

int	word_len(int *i, char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[*i] != '\0' && is_sep(str[*i], charset))
		(*i)++;
	while (str[*i] != '\0' && !is_sep(str[*i], charset))
	{
		(*i)++;
		len++;
	}
	return (len);
}

char	**fill_arr(int i, char *str, char *charset, char **strarr)
{
	int	s;
	int	scan;
	int	arr;

	arr = 0;
	s = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset) && s == 0)
		{
			s = 1;
			scan = 0;
		}
		if (s == 1 && !is_sep(str[i], charset))
			strarr[arr][scan++] = str[i];
		if ((is_sep(str[i], charset) && s == 1) || (!str[i] && s == 1))
		{
			strarr[arr][scan] = '\0';
			arr++;
			scan = 0;
			s = 0;
		}
		i++;
	}
	return (strarr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		strpos;
	char	**strarr;

	if (str == 0 || charset == 0)
	{
		strarr = malloc(1);
		strarr[0] = 0;
		return (strarr);
	}
	i = 0;
	strpos = 0;
	strarr = malloc((count_words(str, charset) + 1) * sizeof(char *));
	while (i < count_words(str, charset))
	{
		strarr[i] = malloc((word_len(&strpos, str, charset) + 1)
				* sizeof(char));
		i++;
	}
	strarr[count_words(str, charset)] = 0;
	return (fill_arr(0, str, charset, strarr));
}
