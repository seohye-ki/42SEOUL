/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:13 by sumilee           #+#    #+#             */
/*   Updated: 2023/10/10 20:30:59 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	if (dst != src)
	{
		p = (unsigned char *)src;
		if (dst <= src)
		{
			while (i < len)
			{
				*((unsigned char *)dst + i) = p[i];
				i++;
			}
		}
		else
		{
			i = len;
			while (i-- > 0)
				*((unsigned char *)dst + i) = p[i];
		}
	}
	return (dst);
}
