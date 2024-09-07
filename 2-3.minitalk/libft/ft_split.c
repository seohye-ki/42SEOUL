/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:22:55 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/09 19:48:53 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char sep)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep)
		{
			while (1)
			{
				if (str[i] == sep || str[i] == '\0')
				{
					count++;
					break ;
				}
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_dup(char const *str, char sep)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (str[i] != sep && str[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[i] != sep && str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_free_str(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		size;
	int		i;

	i = 0;
	size = ft_count_word(s, c);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (strs == NULL)
		return (NULL);
	strs[size] = 0;
	while (*s && i < size)
	{
		while (*s == c && *s != '\0')
			s++;
		strs[i] = ft_dup(s, c);
		if (strs[i] == 0)
		{
			ft_free_str(strs, i + 1);
			return (NULL);
		}
		i++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (strs);
}
