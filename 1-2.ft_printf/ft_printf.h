/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:26:42 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/11 14:59:59 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*utils*/
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int num);
/*type*/
int		print_char(int c);
int		print_str(char *str);
int		print_demical(int num);
int		print_unsigned_demical(unsigned int num);
int		print_ptr(unsigned long long num);
int		print_hex(unsigned int num, char c);
/*ft_printf*/
int		ft_printf(const char *format, ...);

#endif