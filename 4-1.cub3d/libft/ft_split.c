/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:23:38 by sumilee           #+#    #+#             */
/*   Updated: 2023/10/10 15:46:10 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_word(char const *str, char c)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	if (c == 0)
		return (1);
	while (str[i] && str[i] == c)
		i++;
	if (str[i] != '\0')
	{
		cnt = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

static void	ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	*fill_arr(char **arr, size_t j, size_t len)
{
	arr[j] = (char *)malloc(sizeof(char) * (len + 1));
	if (arr[j] == NULL)
	{
		while (j >= 0)
			free (arr[j--]);
		free(arr);
		return (NULL);
	}
	return (arr[j]);
}

static size_t	split_len(char const *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		i;
	size_t		j;
	size_t		len;

	arr = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s[++i])
	{
		len = split_len(s, i, c);
		if (len != 0)
		{
			if (fill_arr(arr, ++j, len) == NULL)
				return (NULL);
			ft_strncpy(arr[j], s + i, len);
			i = i + len - 1;
		}
	}
	arr[j + 1] = NULL;
	return (arr);
}
