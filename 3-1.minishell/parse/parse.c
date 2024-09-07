/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:34:52 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/26 15:46:17 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

int	parsing(t_parsedata *parse, t_list **pipe, t_list *env)
{
	parse->token_head = NULL;
	*pipe = NULL;
	parsing_env(parse, env);
	if (split_token(&(parse->token_head), parse->env_str))
	{
		error_msg_only("syntax error", 0, 0);
		update_env("?", "258", env);
		return (1);
	}
	if (parse->token_head != NULL)
	{
		if (beautify_token(&(parse->token_head), pipe))
		{
			error_msg_only("syntax error", 0, 0);
			update_env("?", "258", env);
			return (1);
		}
	}
	return (0);
}
