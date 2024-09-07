/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:29:18 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/01 12:19:31 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "util.h"
#include <stdio.h>
#include <sys/wait.h>

static int	check_status(int *status, int sig_flag)
{
	int	exit_code;

	exit_code = 0;
	if (WIFEXITED(*status))
		exit_code = WEXITSTATUS(*status);
	if (WIFSIGNALED(*status))
		exit_code = 128 + WTERMSIG(*status);
	if (sig_flag > 0)
	{
		if (sig_flag == SIGQUIT)
			printf("Quit: 3\n");
		if (sig_flag == SIGINT)
			printf("\n");
	}
	return (exit_code);
}

int	wait_and_update_exit_code(pid_t *pid)
{
	int		i;
	int		status;
	pid_t	wait_pid;
	int		exit_code;
	int		sig_flag;

	i = 0;
	sig_flag = 0;
	while (pid && pid[i])
	{
		wait_pid = waitpid(pid[i], &status, 0);
		if (wait_pid < 0)
			error_exit("wait error", 0, 0, EXIT_FAILURE);
		if (WIFSIGNALED(status))
			sig_flag = WTERMSIG(status);
		i++;
	}
	exit_code = check_status(&status, sig_flag);
	return (exit_code);
}

char	**lst_to_envp(t_list *env)
{
	t_list	*cur;
	int		cnt;
	char	**envp;

	cnt = 0;
	cur = env;
	while (cur != NULL)
	{
		cnt++;
		cur = cur->next;
	}
	envp = ft_malloc_err(sizeof(char *) * (cnt + 1));
	envp[cnt] = NULL;
	cnt = 0;
	cur = env;
	while (cur != NULL)
	{
		envp[cnt] = ft_strdup_err((char *)cur->content);
		cnt++;
		cur = cur->next;
	}
	return (envp);
}

int	check_valid_name(char *cmd, char *arg, char sep)
{
	int	i;

	if (arg && arg[0] != '_' && ft_isalpha(arg[0]) == 0)
	{
		error_msg_only("not a valid identifier", cmd, arg);
		return (-1);
	}
	i = 1;
	while (arg && arg[i] && arg[i] != sep)
	{
		if (arg[i] != '_' && ft_isalnum(arg[i]) == 0)
		{
			error_msg_only("not a valid identifier", cmd, arg);
			return (-1);
		}
		i++;
	}
	return (i);
}
