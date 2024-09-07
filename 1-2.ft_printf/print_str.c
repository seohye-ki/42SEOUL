/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:21:34 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/11 16:04:27 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	ssize_t	len;

	if (str == NULL)
		len = write(1, "(null)", 6);
	else
		len = write(1, str, ft_strlen(str));
	return (len);
}