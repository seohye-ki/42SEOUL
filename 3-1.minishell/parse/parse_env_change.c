/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_change.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:34:51 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/26 02:49:16 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

static void	change_loop(t_parsedata *data, char *src, size_t *j)
{
	size_t	k;

	k = 0;
	while (src[k])
		data->env_str[(*j)++] = src[k++];
}

static void	change_default_loop(t_parsedata *data, char *src, size_t *j)
{
	size_t	k;
	char	quote;

	k = 0;
	while (src[k])
	{
		if (ft_isquote(src[k]) || ft_ispipe(src[k]) || ft_isredi(src[k]))
		{
			quote = '"';
			if (ft_isquote(src[k]) == 2)
				quote = '\'';
			data->env_str[(*j)++] = quote;
			data->env_str[(*j)++] = src[k++];
			data->env_str[(*j)++] = quote;
		}
		else
			data->env_str[(*j)++] = src[k++];
	}
}

void	change_default(t_parsedata *data, size_t *i, size_t *j, t_list *env)
{
	size_t	k;
	char	*name;
	char	*src;
	int		m_flag;

	name = get_env_name(data->str + *i);
	src = find_env(name, env);
	k = 0;
	m_flag = 0;
	while (src[k])
	{
		if (ft_isquote(src[k]) || ft_ispipe(src[k]) || ft_isredi(src[k]))
			m_flag = 1;
		k++;
	}
	if (m_flag)
		change_default_loop(data, src, j);
	else
		change_loop(data, src, j);
	(*i) += ft_strlen(name);
	free(name);
	free(src);
}

static void	change_quote_loop(t_parsedata *data, char *src, size_t *j)
{
	size_t	k;
	char	quote;

	k = 0;
	data->env_str[(*j)++] = '"';
	while (src[k])
	{
		if (ft_isquote(src[k]) || ft_ispipe(src[k])
			|| ft_isredi(src[k]) || ft_isspace(src[k]))
		{
			quote = '"';
			if (ft_isquote(src[k]) == 2)
				quote = '\'';
			data->env_str[(*j)++] = quote;
			data->env_str[(*j)++] = src[k++];
			data->env_str[(*j)++] = quote;
		}
		else
			data->env_str[(*j)++] = src[k++];
	}
	data->env_str[(*j)++] = '"';
}

void	change_quote(t_parsedata *data, size_t *i, size_t *j, t_list *env)
{
	size_t	k;
	char	*name;
	char	*src;
	int		m_flag;

	name = get_env_name(data->str + *i);
	src = find_env(name, env);
	k = 0;
	m_flag = 0;
	while (src[k])
	{
		if (ft_isquote(src[k]) || ft_ispipe(src[k])
			|| ft_isredi(src[k]) || ft_isspace(src[k]))
			m_flag = 1;
		k++;
	}
	if (m_flag)
		change_quote_loop(data, src, j);
	else
		change_loop(data, src, j);
	(*i) += ft_strlen(name);
	free(name);
	free(src);
}
