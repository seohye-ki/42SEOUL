/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:03:41 by sumilee           #+#    #+#             */
/*   Updated: 2023/10/10 16:09:12 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_set(char str, char const *set)
{
	int	i;

	i = 0;
	if (set == NULL)
		return (0);
	while (set[i])
	{
		if (str == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_len;
	char	*result;
	size_t	i;
	size_t	j;

	i = -1;
	str_len = ft_strlen(s1);
	while (s1[++i] && is_set(s1[i], set) == 1)
		str_len--;
	if (str_len >= 2)
	{
		j = ft_strlen(s1);
		while (j > 0 && is_set(s1[--j], set) == 1)
			str_len--;
	}
	result = (char *)malloc(str_len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1 + i, str_len + 1);
	return (result);
}
