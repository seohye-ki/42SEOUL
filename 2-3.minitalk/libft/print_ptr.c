/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:51:34 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/16 16:32:54 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	count_ptr_len(unsigned long long n)
{
	int	count;

	count = 2;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static char	*ft_make_ptr(unsigned long long num)
{
	int		size;
	char	*new_str;
	char	*hexchar;

	hexchar = "0123456789abcdef";
	size = count_ptr_len(num);
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[size] = '\0';
	while (--size)
	{
		new_str[size] = hexchar[num % 16];
		num /= 16;
	}
	new_str[size] = hexchar[num % 16];
	new_str[0] = '0';
	new_str[1] = 'x';
	return (new_str);
}

int	print_ptr(unsigned long long num)
{
	ssize_t	len;
	char	*str;

	str = ft_make_ptr(num);
	if (str == NULL)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
