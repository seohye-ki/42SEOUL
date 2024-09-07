/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:54:16 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/26 15:52:09 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	error_exit(char *msg, char *cmd, char *arg, int code)
{
	if (code != 0 && msg != NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		if (cmd != NULL)
		{
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": ", 2);
		}
		if (arg != NULL)
		{
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": ", 2);
		}
		ft_putstr_fd(msg, 2);
		write(2, "\n", 1);
	}
	exit(code);
}

void	error_msg_only(char *msg, char *cmd, char *arg)
{
	if (msg != NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		if (cmd != NULL)
		{
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": ", 2);
		}
		if (arg != NULL)
		{
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": ", 2);
		}
		ft_putstr_fd(msg, 2);
		write(2, "\n", 1);
	}
}

void	*ft_malloc_err(size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(size);
	if (ptr == NULL)
		error_exit("malloc failed", 0, 0, EXIT_FAILURE);
	return ((void *)ptr);
}

char	*ft_strjoin_sep(char const *s1, char const *s2, char const *sep)
{
	size_t	strlen;
	char	*arr;

	strlen = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	arr = (char *)malloc(sizeof(char) * (strlen + 1));
	if (arr == NULL)
		error_exit("malloc failed.", 0, 0, EXIT_FAILURE);
	arr[0] = '\0';
	ft_strcat(arr, s1);
	ft_strcat(arr, sep);
	ft_strcat(arr, s2);
	return (arr);
}
