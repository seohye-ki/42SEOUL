/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:04:12 by sumilee           #+#    #+#             */
/*   Updated: 2023/10/10 22:01:09 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	temp;

	if (n < 10 && n >= 0)
		temp = '0' + n;
	if (n > -10 && n < 0)
	{
		write (fd, "-", 1);
		temp = '0' - n;
	}
	if (n >= 10 || n <= -10)
	{
		if (n < 0)
			temp = '0' - n % 10;
		if (n >= 0)
			temp = '0' + n % 10;
		n = n / 10;
		ft_putnbr_fd(n, fd);
	}
	write(fd, &temp, 1);
}
