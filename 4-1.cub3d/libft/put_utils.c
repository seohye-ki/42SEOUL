/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:56:34 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/02 21:29:57 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int *len)
{
	int	char_cnt;

	char_cnt = write(1, &c, 1);
	if (char_cnt == -1)
		return (-1);
	(*len)++;
	return (1);
}

int	ft_putstr(char *s, int *len)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_putchar(s[i], len) == -1)
			return (-1);
		i++;
	}
	return (1);
}
