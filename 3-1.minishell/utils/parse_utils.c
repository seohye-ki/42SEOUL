/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:43:31 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/26 01:23:02 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_ispipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int	ft_isredi(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	ft_isquote(char c)
{
	if (c == '\'')
		return (1);
	else if (c == '"')
		return (2);
	return (0);
}

int	check_token_type(char *str)
{
	if (*str == '<' && *(str + 1) == '<')
		return (TYPE_HEREDOC);
	else if (*str == '<' && *(str + 1) != '<')
		return (TYPE_INPUT);
	else if (*str == '>' && *(str + 1) != '>')
		return (TYPE_OUTPUT_T);
	else if (*str == '>' && *(str + 1) == '>')
		return (TYPE_OUTPUT_A);
	else if (ft_ispipe(*str))
		return (TYPE_PIPE);
	else
		return (TYPE_DEFAULT);
}
