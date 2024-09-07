/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:34:33 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/27 23:21:35 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "util.h"
#include <dirent.h>

static int	is_with_path(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static char	**split_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			path = ft_split(&envp[i][5], ':');
			if (path == NULL)
				error_exit("malloc failed.", 0, 0, EXIT_FAILURE);
			break ;
		}
		i++;
	}
	return (path);
}

static char	*find_cmd(char **path, char *cmd)
{
	char	*path_join;
	int		i;

	path_join = NULL;
	i = 0;
	while (path[i])
	{
		path_join = ft_strjoin_sep(path[i], cmd, "/");
		if (path_join == NULL)
			error_exit("path / command error.", 0, 0, EXIT_FAILURE);
		if (access(path_join, X_OK) == 0)
			break ;
		else
			free(path_join);
		path_join = NULL;
		i++;
	}
	return (path_join);
}

static void	exec_pathjoin(char **cmd, char **envp)
{
	char	**path;
	char	*path_join;
	int		i;

	path_join = NULL;
	path = split_path(envp);
	if (path == NULL)
		error_exit("No such file or directory", cmd[0], 0, 127);
	if (cmd[0] != NULL && cmd[0][0] != '\0')
		path_join = find_cmd(path, cmd[0]);
	if (cmd[0] == NULL)
		error_exit("command not found", 0, 0, 127);
	if (cmd[0][0] == '\0' || path_join == NULL)
		error_exit("command not found", cmd[0], 0, 127);
	i = 0;
	while (path[i])
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	if (execve(path_join, cmd, envp) < 0)
		error_exit("exec failed.", 0, 0, 126);
}

void	exec_general_cmd(char **cmd, t_list *env)
{
	char	**envp;
	DIR		*dir_p;

	envp = lst_to_envp(env);
	if (is_with_path(cmd[0]) > 0)
	{
		if (access(cmd[0], F_OK) != 0)
			error_exit("No such file or directory", cmd[0], 0, 127);
		dir_p = opendir(cmd[0]);
		if (dir_p != NULL)
		{
			error_msg_only("is a directory", cmd[0], 0);
			closedir(dir_p);
			exit(126);
		}
		if (access(cmd[0], X_OK) != 0)
			error_exit("Permission denied", cmd[0], 0, 126);
		if (execve(cmd[0], cmd, envp) < 0)
			error_exit("exec failed.", 0, 0, 126);
	}
	else
		exec_pathjoin(cmd, envp);
}
