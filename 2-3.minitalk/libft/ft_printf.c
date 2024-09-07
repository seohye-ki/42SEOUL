/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:07:25 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/23 12:53:08 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_specifier(char c)
{
	char	*specifier;
	int		i;

	specifier = "csdiupxX%";
	i = 0;
	while (specifier[i])
	{
		if (c == specifier[i])
			return (1);
		i++;
	}
	return (0);
}

static void	chk_specifier(va_list *ap, char c, int *total_len)
{
	int	len;

	if (c == 'c')
		len = print_char(va_arg(*ap, int));
	else if (c == 's')
		len = print_str(va_arg(*ap, char *));
	else if (c == 'd' || c == 'i')
		len = print_demical(va_arg(*ap, int));
	else if (c == 'u')
		len = print_unsigned_demical(va_arg(*ap, unsigned int));
	else if (c == 'p')
		len = print_ptr(va_arg(*ap, unsigned long long));
	else if (c == 'x' || c == 'X')
		len = print_hex(va_arg(*ap, unsigned int), c);
	else
		len = write(1, "%", 1);
	if (len < 0)
		*total_len = -1;
	else
		*total_len += len;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total_len;

	total_len = 0;
	va_start(ap, format);
	while (*format && total_len != -1)
	{
		if (*format == '%')
		{
			format++;
			if (is_specifier(*format) == 0)
				break ;
			chk_specifier(&ap,*format, &total_len);
		}
		else
		{
			if (write(1, &format[0], 1) < 0)
				total_len = -1;
			else
				total_len++;
		}
		format++;
	}
	va_end(ap);
	return (total_len);
}
