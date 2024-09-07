/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:03:50 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/02 16:41:38 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "util.h"
#include <unistd.h>

void	delete_tmpfile(t_execdata *data)
{
	int	i;

	i = 0;
	while (data->file_arr && data->file_arr[i])
	{
		if (access(data->file_arr[i], F_OK) == 0
			&& unlink(data->file_arr[i]) < 0)
			error_msg_only("file unlink failed", data->file_arr[i], 0);
		i++;
	}
}

void	end_exec(t_execdata *data, int exit_code)
{
	char	*code;

	code = ft_itoa_err(exit_code);
	update_env("?", code, data->env);
	free (code);
	delete_tmpfile(data);
	free_arr(data->eof_arr);
	free_arr(data->file_arr);
	if (data->pid != NULL)
		free(data->pid);
	ft_lstclear(&data->pipe, free_tokens_in_pipe);
}
