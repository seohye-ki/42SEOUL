/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:47:20 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/11 16:03:36 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hexstr_len(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*ft_make_hexstr(unsigned int num, char c)
{
	int		size;
	char	*new_str;
	char	*hexchar;
	char	*hexlchar;

	hexchar = "0123456789abcdef";
	hexlchar = "0123456789ABCDEF";
	size = count_hexstr_len(num);
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[size] = '\0';
	while (--size)
	{
		if (c == 'x')
			new_str[size] = hexchar[num % 16];
		else
			new_str[size] = hexlchar[num % 16];
		num /= 16;
	}
	if (c == 'x')
		new_str[size] = hexchar[num % 16];
	else
		new_str[size] = hexlchar[num % 16];
	return (new_str);
}

int	print_hex(unsigned int num, char c)
{
	ssize_t	len;
	char	*str;

	str = ft_make_hexstr(num, c);
	if (str == NULL)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
