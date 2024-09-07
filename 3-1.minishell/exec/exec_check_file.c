/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_check_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:45:05 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/26 02:41:51 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parse.h"
#include "util.h"
#include <unistd.h>
#include <fcntl.h>

static int	check_input_file(char *file)
{
	if (access(file, F_OK) != 0)
	{
		error_msg_only("No such file or directory", file, 0);
		return (-1);
	}
	else if (access(file, R_OK) != 0)
	{
		error_msg_only("Permission denied", file, 0);
		return (-1);
	}
	return (0);
}

static int	check_output_file(char *file, char mode)
{
	int	fd;

	if (mode == 'a')
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
		{
			error_msg_only("Permission denied", file, 0);
			return (-1);
		}
		close(fd);
	}
	else if (mode == 't')
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
		{
			error_msg_only("Permission denied", file, 0);
			return (-1);
		}
		close(fd);
	}
	return (0);
}

int	check_file_open(t_list *pipe_tokens)
{
	t_list	*cur;
	t_token	*token;

	cur = pipe_tokens;
	while (cur != NULL)
	{
		token = cur->content;
		if (token->type == TYPE_INPUT)
			if (check_input_file(token->str) < 0)
				return (-1);
		if (token->type == TYPE_OUTPUT_A)
			if (check_output_file(token->str, 'a') < 0)
				return (-1);
		if (token->type == TYPE_OUTPUT_T)
			if (check_output_file(token->str, 't') < 0)
				return (-1);
		cur = cur->next;
	}
	return (0);
}
