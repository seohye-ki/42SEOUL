/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:40:13 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/27 22:42:06 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "exec.h"
#include "util.h"

static void	remove_env(char *name, t_list *env)
{
	t_list	*cur;
	t_list	*tmp;

	cur = env;
	if (name == NULL)
		return ;
	while (cur->next != NULL)
	{
		if (find_env_name((char *)cur->next->content, name, 0))
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			ft_lstdelone(tmp, free);
		}
		cur = cur->next;
		if (cur == NULL)
			return ;
	}
}

int	exec_unset(char **cmd, t_list *env)
{
	int		i;
	int		name_len;
	int		err_flag;

	if (check_cmd_option(cmd) < 0)
		return (-1);
	i = 0;
	err_flag = 0;
	while (cmd[++i])
	{
		name_len = check_valid_name(cmd[0], cmd[i], '\0');
		if (name_len < 0)
		{
			err_flag = 1;
			continue ;
		}
		remove_env(cmd[i], env);
	}
	if (err_flag == 1)
		return (-1);
	return (0);
}
