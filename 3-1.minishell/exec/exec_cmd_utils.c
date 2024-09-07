/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:40:55 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/26 02:50:18 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parse.h"
#include "builtin.h"
#include "util.h"

char	**cmd_to_arr(t_list *pipe_tokens)
{
	t_list	*cur;
	int		cnt;
	char	**cmd;

	cnt = 0;
	cur = pipe_tokens;
	while (cur != NULL)
	{
		if (((t_token *)cur->content)->type == TYPE_DEFAULT)
			cnt++;
		cur = cur->next;
	}
	if (cnt == 0)
		return (NULL);
	cmd = ft_malloc_err(sizeof(char *) * (cnt + 1));
	cmd[cnt] = NULL;
	cnt = -1;
	cur = pipe_tokens;
	while (cur != NULL)
	{
		if (((t_token *)cur->content)->type == 0)
			cmd[++cnt] = ft_strdup_err(((t_token *)cur->content)->str);
		cur = cur->next;
	}
	return (cmd);
}

int	is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (-1);
	if (!ft_memcmp("echo", cmd, 5))
		return (1);
	if (!ft_memcmp("cd", cmd, 3))
		return (2);
	if (!ft_memcmp("pwd", cmd, 4))
		return (3);
	if (!ft_memcmp("export", cmd, 7))
		return (4);
	if (!ft_memcmp("unset", cmd, 6))
		return (5);
	if (!ft_memcmp("env", cmd, 4))
		return (6);
	if (!ft_memcmp("exit", cmd, 5))
		return (7);
	return (0);
}

int	exec_cmd(char **cmd, t_list *env, int pipe_flag)
{
	if (cmd == NULL)
		return (0);
	else if (is_builtin(cmd[0]) == 1)
		return (exec_echo(cmd));
	else if (is_builtin(cmd[0]) == 2)
		return (exec_cd(cmd, env));
	else if (is_builtin(cmd[0]) == 3)
		return (exec_pwd(cmd));
	else if (is_builtin(cmd[0]) == 4)
		return (exec_export(cmd, env));
	else if (is_builtin(cmd[0]) == 5)
		return (exec_unset(cmd, env));
	else if (is_builtin(cmd[0]) == 6)
		return (exec_env(cmd, env));
	else if (is_builtin(cmd[0]) == 7)
		exec_exit(cmd, pipe_flag, env);
	else
		exec_general_cmd(cmd, env);
	return (0);
}
