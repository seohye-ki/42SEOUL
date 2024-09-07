/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:14:04 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/26 18:32:40 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "util.h"
#include <errno.h>

static char	*get_current_path(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		error_exit("malloc failed", 0, 0, EXIT_FAILURE);
	return (path);
}

static int	change_dir(char *dest_path, char *arg, t_list *env)
{
	char	*current_path;
	char	*new_pwd;

	current_path = get_current_path();
	if (chdir(dest_path) < 0)
	{
		if (errno == EACCES || errno == EFAULT)
			error_msg_only("Permission denied", "cd", arg);
		else if (errno == ENOENT)
			error_msg_only("No such file or directory", "cd", arg);
		else if (errno == ENOTDIR)
			error_msg_only("Not a directory", "cd", arg);
		else
			error_msg_only("Error occured", "cd", arg);
		free(current_path);
		return (-1);
	}
	update_env("OLDPWD", current_path, env);
	free(current_path);
	new_pwd = get_current_path();
	update_env("PWD", new_pwd, env);
	free(new_pwd);
	return (0);
}

static int	to_directory(char *path, char **cmd, t_list *env)
{
	char	*dest_path;

	dest_path = find_env(path, env);
	if (dest_path == NULL)
	{
		error_msg_only("Environment variables not set", 0, 0);
		return (-1);
	}
	if (dest_path && dest_path[0] == '\0')
	{
		free(dest_path);
		error_msg_only("not set", cmd[0], path);
		return (-1);
	}
	if (change_dir(dest_path, 0, env) < 0)
	{
		free(dest_path);
		return (-1);
	}
	free(dest_path);
	return (0);
}

static int	relative_change_dir(char *arg, t_list *env)
{
	char	*dest_path;
	char	*current_path;

	current_path = get_current_path();
	dest_path = ft_strjoin_sep(current_path, arg, "/");
	free(current_path);
	if (change_dir(dest_path, arg, env) < 0)
	{
		free(dest_path);
		return (-1);
	}
	free(dest_path);
	return (0);
}

int	exec_cd(char **cmd, t_list *env)
{
	if (check_cmd_option(cmd) < 0)
		return (-1);
	if (cmd[1] == NULL)
		return (to_directory("HOME", cmd, env));
	else
	{
		if (cmd[1][0] == '/')
			return (change_dir(cmd[1], cmd[1], env));
		else
			return (relative_change_dir(cmd[1], env));
	}
}
