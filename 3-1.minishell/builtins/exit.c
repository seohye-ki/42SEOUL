/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:15:12 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/02 16:22:56 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "util.h"
#include <stdio.h>

static void	exit_numeric_arg(char **cmd)
{
	error_msg_only("numeric argument required", cmd[0], cmd[1]);
	exit(255);
}

static long long	exit_atol(char **cmd)
{
	long long	i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (cmd[1][i] && ft_isspace(cmd[1][i]))
		i++;
	if (cmd[1][i] && (cmd[1][i] == '-' || cmd[1][i] == '+'))
	{
		if (cmd[1][i] == '-')
			sign = -1;
		i++;
		if (cmd[1][i] == 0)
			exit_numeric_arg(cmd);
	}
	while (cmd[1][i] && (cmd[1][i] >= '0' && cmd[1][i] <= '9'))
		result = result * 10 + (cmd[1][i++] - '0');
	while (cmd[1][i] && ft_isspace(cmd[1][i]))
			i++;
	if (cmd[1][i] && (cmd[1][i] < '0' || cmd[1][i] > '9'))
		exit_numeric_arg(cmd);
	return (sign * result);
}

void	exec_exit(char **cmd, int pipe_flag, t_list *env)
{
	long long	exit_code;
	char		*code;

	if (pipe_flag == 0)
		printf("exit\n");
	if (cmd == NULL || cmd[1] == NULL)
	{
		code = find_env("?", env);
		exit_code = ft_atoi(code);
		free(code);
		exit(exit_code);
	}
	exit_code = exit_atol(cmd);
	if (cmd[2] != NULL)
	{
		error_msg_only("too many arguments", cmd[0], 0);
		update_env("?", "1", env);
		return ;
	}
	exit((unsigned char)exit_code);
}
