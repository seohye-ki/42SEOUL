/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_demical.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:24:51 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/11 16:04:35 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_ui_size(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_uitoa(unsigned int num)
{
	int			size;
	char		*num_str;

	size = count_ui_size(num);
	num_str = (char *)malloc(sizeof(char) * (size + 1));
	if (num_str == 0)
		return (NULL);
	num_str[size] = '\0';
	while (--size)
	{
		num_str[size] = num % 10 + '0';
		num /= 10;
	}
	num_str[size] = num + '0';
	return (num_str);
}

int	print_unsigned_demical(unsigned int num)
{
	ssize_t	len;
	char	*str;

	str = ft_uitoa(num);
	if (str == NULL)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
