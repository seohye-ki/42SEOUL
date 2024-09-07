/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:36:18 by seohyeki          #+#    #+#             */
/*   Updated: 2023/10/31 17:44:12 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	i = 0;
	if ((haystack == 0 && len == 0) || *needle == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && i < len)
	{
		if (*haystack == needle[0] && ft_strlen(needle) + i <= len)
		{
			if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return (NULL);
}
