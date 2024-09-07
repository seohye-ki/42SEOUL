/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:50:33 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/08 12:31:05 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	error_exit(char *msg)
{
	if (msg != NULL)
	{
		ft_putstr_fd("Error!\n", 2);
		ft_putstr_fd(msg, 2);
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

void	*ft_malloc_err(size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(size);
	if (ptr == NULL)
		error_exit("Malloc failed.");
	return ((void *)ptr);
}

char	*ft_strdup_err(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*dest;

	dest = ft_malloc_err(sizeof(char) * (ft_strlen(src) + 1));
	src_len = ft_strlen(src);
	i = 0;
	while (i < src_len + 1)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_atoi_err(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i++] - '0');
		if (result > 255)
			error_exit("Wrong color information.");
	}
	if (sign < 0 || nptr[i])
		error_exit("Wrong color information.");
	return (result);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
