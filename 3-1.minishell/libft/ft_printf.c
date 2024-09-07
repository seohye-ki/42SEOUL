/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:12:36 by sumilee           #+#    #+#             */
/*   Updated: 2024/02/01 22:39:39 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_index(const char *s, va_list *ptr, int i, int *len)
{
	char	*spec;
	int		j;
	int		(*fp[8])(va_list *, int *);

	spec = "cspdiuxX%";
	j = 0;
	fp[0] = pr_char;
	fp[1] = pr_str;
	fp[2] = pr_ptr;
	fp[3] = pr_int;
	fp[4] = pr_int;
	fp[5] = pr_uns;
	fp[6] = pr_lohex;
	fp[7] = pr_uphex;
	while (j < 8)
	{
		if (s[i] == spec[j])
			return (fp[j](ptr, len));
		j++;
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(ptr, s);
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[++i] == '%')
			{
				if (ft_putchar('%', &len) == -1)
					return (-1);
			}
			else if (print_index(s, &ptr, i, &len) == -1)
				return (-1);
		}
		else
			if (ft_putchar(s[i], &len) == -1)
				return (-1);
	}
	va_end(ptr);
	return (len);
}
