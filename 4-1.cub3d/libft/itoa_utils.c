/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:55:57 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/30 16:24:00 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsigned_itoa(unsigned int n)
{
	unsigned int	cnt;
	unsigned int	temp;
	char			*arr;

	cnt = 0;
	temp = n;
	if (temp == 0)
		cnt = 1;
	while (temp != 0)
	{
		temp = temp / 10;
		cnt++;
	}
	arr = ft_pos(n, cnt);
	return (arr);
}
