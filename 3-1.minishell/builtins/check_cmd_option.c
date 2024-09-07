/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:56:19 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/26 02:37:33 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "util.h"

int	check_cmd_option(char **cmd)
{
	char	tmp[3];

	if (cmd[1] && cmd[1][0] == '-' && cmd[1][1] != '\0')
	{
		tmp[0] = '-';
		tmp[1] = cmd[1][1];
		tmp[2] = '\0';
		error_msg_only("invalid option", cmd[0], tmp);
		return (-1);
	}
	return (0);
}
