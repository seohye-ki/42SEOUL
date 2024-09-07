/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:33:25 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/02 16:09:15 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_parsedata	parse;
	t_execdata	data;

	if (argc != 1 || argv[1] != NULL)
		return (1);
	data.env = envp_to_lst(envp);
	while (1)
	{
		parse.str = prompt_shell(data.env);
		if (parse.str == NULL)
			exec_exit(NULL, 0, data.env);
		if (*parse.str)
		{
			if (parsing(&parse, &(data.pipe), data.env) == 0 \
				&& data.pipe != NULL)
				end_exec(&data, exec(&data));
			free(parse.env_str);
		}
		free(parse.str);
	}
	return (0);
}
