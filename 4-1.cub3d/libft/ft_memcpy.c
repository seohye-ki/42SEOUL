/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:13 by sumilee           #+#    #+#             */
/*   Updated: 2023/10/10 20:30:06 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	if (dst != src)
	{
		p = (unsigned char *)src;
		while (i < n)
		{
			*((unsigned char *)dst + i) = p[i];
			i++;
		}
	}
	return (dst);
}
