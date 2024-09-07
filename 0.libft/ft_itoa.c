/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:42:22 by seohyeki          #+#    #+#             */
/*   Updated: 2023/10/31 14:32:04 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(long long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		n *= -1;
		count += 1;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			size;
	char		*num_str;

	num = (long long)n;
	size = count_size(num);
	num_str = (char *)malloc(sizeof(char) * (size + 1));
	if (num_str == NULL)
		return (NULL);
	num_str[size] = '\0';
	if (num < 0)
	{
		num_str[0] = '-';
		num *= -1;
	}
	while (--size)
	{
		num_str[size] = num % 10 + '0';
		num /= 10;
	}
	if (n >= 0)
		num_str[size] = num + '0';
	return (num_str);
}
