/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:58:11 by sumilee           #+#    #+#             */
/*   Updated: 2024/02/01 22:39:15 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pr_char(va_list *ptr, int *len)
{
	char	c;

	c = va_arg(*ptr, int);
	return (ft_putchar(c, len));
}

int	pr_str(va_list *ptr, int *len)
{
	char	*str;

	str = va_arg(*ptr, char *);
	if (str == NULL)
		str = "(null)";
	return (ft_putstr(str, len));
}

int	pr_int(va_list *ptr, int *len)
{
	int		num;
	char	*result;

	num = va_arg(*ptr, int);
	result = ft_itoa(num);
	if (result == NULL || ft_putstr(result, len) == -1)
	{
		free (result);
		return (-1);
	}
	free (result);
	return (1);
}

int	pr_uns(va_list *ptr, int *len)
{
	unsigned int	num;
	char			*result;

	num = va_arg(*ptr, unsigned int);
	result = ft_unsigned_itoa(num);
	if (result == NULL || ft_putstr(result, len) == -1)
	{
		free (result);
		return (-1);
	}
	free (result);
	return (1);
}
