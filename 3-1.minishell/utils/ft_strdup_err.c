/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:02:59 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/26 18:17:30 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static void	ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	if (src != NULL)
		src_len = ft_strlen(src);
	while (dest != NULL && src != NULL && i < src_len + 1)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strdup_err(const char *s1)
{
	char	*dest;

	dest = NULL;
	if (s1 != NULL)
		dest = (char *)ft_malloc_err(sizeof(char) * (ft_strlen(s1) + 1));
	ft_strcpy(dest, s1);
	return (dest);
}
