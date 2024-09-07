/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:22:02 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/29 17:57:48 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "util.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>

static int	is_eof(char *eof, char *buff)
{
	if (ft_memcmp(eof, buff, ft_strlen(eof) + 1) == 0)
		return (1);
	return (0);
}

static void	input_to_heredoc(t_execdata *data, int i)
{
	char	*buff;
	int		fd;

	fd = open(data->file_arr[i], O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		error_exit("file open failed", 0, 0, EXIT_FAILURE);
	while (1)
	{
		buff = prompt_heredoc();
		if (buff == NULL)
			break ;
		if (is_eof(data->eof_arr[i], buff) == 1)
		{
			free(buff);
			break ;
		}
		buff = chk_buff(buff, data->env);
		write(fd, buff, ft_strlen(buff));
		write(fd, "\n", 1);
		free(buff);
	}
	close(fd);
}

static int	is_heredoc_signaled(t_list *env)
{
	char	*exit_code;

	exit_code = find_env("?", env);
	if (ft_memcmp(exit_code, "100", 4) == 0)
	{
		free(exit_code);
		return (1);
	}
	free(exit_code);
	return (0);
}

int	here_document(t_execdata *data)
{
	int		i;
	int		exit_num;
	char	*exit_code;

	i = 0;
	before_heredoc(data);
	data->pid[0] = fork();
	if (data->pid[0] < 0)
		error_exit("fork failed", 0, 0, EXIT_FAILURE);
	if (data->pid[0] == 0)
	{
		while (i < data->doc_cnt)
			input_to_heredoc(data, i++);
		exit(EXIT_SUCCESS);
	}
	exit_num = wait_and_update_exit_code(data->pid);
	exit_code = ft_itoa_err(exit_num);
	update_env("?", exit_code, data->env);
	free(exit_code);
	return (is_heredoc_signaled(data->env));
}
