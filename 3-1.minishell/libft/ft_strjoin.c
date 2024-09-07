/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:35:33 by sumilee           #+#    #+#             */
/*   Updated: 2024/02/13 13:50:47 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	strlen;
	char	*arr;

	strlen = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (strlen + 1));
	if (arr == NULL)
		return (NULL);
	arr[0] = '\0';
	ft_strcat(arr, s1);
	ft_strcat(arr, s2);
	return (arr);
}
