/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:59:01 by sumilee           #+#    #+#             */
/*   Updated: 2024/02/01 22:39:06 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_print(unsigned long num, int *len, char c)
{
	char			*hex;
	unsigned long	p_num;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (num < 16)
	{
		if (ft_putchar(hex[num], len) == -1)
			return (-1);
	}
	else if (num != 0)
	{
		p_num = num % 16;
		num /= 16;
		if (hex_print(num, len, c) == -1)
			return (-1);
		if (ft_putchar(hex[p_num], len) == -1)
			return (-1);
	}
	return (0);
}

int	pr_ptr(va_list *ptr, int *len)
{
	unsigned long	addr;

	addr = va_arg(*ptr, unsigned long);
	if (ft_putstr("0x", len) == -1 || hex_print(addr, len, 'x') == -1)
		return (-1);
	return (1);
}

int	pr_uphex(va_list *ptr, int *len)
{
	unsigned int	num;

	num = va_arg(*ptr, unsigned int);
	return (hex_print(num, len, 'X'));
}

int	pr_lohex(va_list *ptr, int *len)
{
	unsigned int	num;

	num = va_arg(*ptr, unsigned int);
	return (hex_print(num, len, 'x'));
}
