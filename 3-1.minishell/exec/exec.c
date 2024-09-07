/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:38:45 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/02 17:17:43 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parse.h"
#include "util.h"

static int	count_pipe(t_execdata *data)
{
	t_list	*cur;
	t_list	*cur_token;
	char	*cmd;

	data->pipe_cnt = 0;
	cur = data->pipe;
	cmd = NULL;
	while (cur != NULL)
	{
		data->pipe_cnt++;
		cur_token = cur->content;
		while (cur_token != NULL)
		{
			if (((t_token *)cur_token->content)->type == TYPE_DEFAULT)
			{
				cmd = ((t_token *)cur_token->content)->str;
				break ;
			}
			cur_token = cur_token->next;
		}
		cur = cur->next;
	}
	if (data->pipe_cnt == 1 && is_builtin(cmd) > 0 && is_builtin(cmd) < 8)
		return (1);
	return (0);
}

static int	only_builtin(t_execdata *data)
{
	int		input;
	int		output;
	char	**cmd;
	int		exec_result;

	cmd = cmd_to_arr(data->pipe->content);
	if (check_file_open(data->pipe->content) < 0 || cmd == NULL)
	{
		free_arr(cmd);
		return (1);
	}
	input = open_last_input(data->pipe, data->file_arr);
	output = open_last_output(data->pipe);
	dup_fds(data, input, output);
	if (is_builtin(cmd[0]) == 7)
		delete_tmpfile(data);
	exec_result = exec_cmd(cmd, data->env, 0);
	restore_fds(data, input, output);
	free_arr(cmd);
	if (exec_result < 0)
		return (1);
	return (0);
}

static int	exec_multiple_pipe(t_execdata *data)
{
	data->index = 0;
	while (data->index < data->pipe_cnt)
	{
		if (data->index < data->pipe_cnt - 1)
			if (pipe(data->fd[data->index % 2]) < 0)
				error_exit("pipe failed.", 0, 0, EXIT_FAILURE);
		data->pid[data->index] = fork();
		if (data->pid[data->index] < 0)
			error_exit("fork failed.", 0, 0, EXIT_FAILURE);
		else if (data->pid[data->index] == 0)
		{
			set_sig_term(SIG_DFL, SIG_DFL, 1);
			exec_in_child(data, data->index);
		}
		if (data->index < data->pipe_cnt - 1)
			close(data->fd[data->index % 2][1]);
		if (data->index > 0)
			close(data->fd[(data->index + 1) % 2][0]);
		data->index++;
	}
	return (wait_and_update_exit_code(data->pid));
}

int	exec(t_execdata *data)
{
	init_exec_data(data);
	data->pid = ft_malloc_err(sizeof(pid_t) * 2);
	data->pid[1] = 0;
	if (data->doc_cnt > 0 && here_document(data) > 0)
		return (1);
	if (count_pipe(data) == 1)
		return (only_builtin(data));
	free(data->pid);
	data->pid = ft_malloc_err(sizeof(pid_t) * (data->pipe_cnt + 1));
	data->pid[data->pipe_cnt] = 0;
	return (exec_multiple_pipe(data));
}
