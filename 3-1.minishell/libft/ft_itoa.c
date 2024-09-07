/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:24:58 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/30 16:23:47 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_pos(int n, int cnt)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (cnt + 1));
	if (arr == NULL)
		return (NULL);
	arr[cnt] = '\0';
	while (--cnt >= 0)
	{
		arr[cnt] = n % 10 + '0';
		n = n / 10;
	}
	return (arr);
}

static char	*neg(int n, int cnt)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (cnt + 1));
	if (arr == NULL)
		return (NULL);
	arr[cnt] = '\0';
	while (--cnt >= 1)
	{
		arr[cnt] = (n % 10) * -1 + '0';
		n = n / 10;
	}
	arr[cnt] = '-';
	return (arr);
}

char	*ft_itoa(int n)
{
	int		cnt;
	int		temp;
	char	*arr;

	cnt = 0;
	temp = n;
	if (temp == 0)
		cnt = 1;
	while (temp != 0)
	{
		temp = temp / 10;
		cnt++;
	}
	if (n < 0)
		arr = neg(n, cnt + 1);
	else
		arr = ft_pos(n, cnt);
	return (arr);
}
