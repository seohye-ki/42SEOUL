/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:26:42 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/16 16:32:12 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		print_char(int c);
int		print_str(char *str);
int		print_demical(int num);
int		print_unsigned_demical(unsigned int num);
int		print_ptr(unsigned long long num);
int		print_hex(unsigned int num, char c);
int		ft_printf(const char *format, ...);

#endif