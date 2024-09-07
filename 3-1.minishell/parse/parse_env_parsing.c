/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:06:09 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/26 02:45:57 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

static void	env_in_quote(t_parsedata *data, size_t *i, size_t *j, t_list *env)
{
	data->env_str[(*j)++] = data->str[(*i)++];
	while (ft_isquote(data->str[*i]) != 2 && data->str[*i])
	{
		if (data->str[*i] == '$')
		{
			(*i)++;
			if (ft_isalpha(data->str[*i]) || data->str[*i] == '_'
				|| data->str[*i] == '?')
				change_quote(data, i, j, env);
			else
				data->env_str[(*j)++] = '$';
		}
		else
			data->env_str[(*j)++] = data->str[(*i)++];
	}
	if (data->str[*i])
		data->env_str[(*j)++] = data->str[(*i)++];
}

static void	no_change_vlaue(t_parsedata *data, size_t *i, size_t *j)
{
	data->env_str[*j] = data->str[*i];
	(*j)++;
	(*i)++;
	while (data->str[*i] != '\'' && data->str[*i])
	{
		data->env_str[*j] = data->str[*i];
		(*j)++;
		(*i)++;
	}
	if (data->str[*i])
	{
		data->env_str[*j] = data->str[*i];
		(*j)++;
		(*i)++;
	}
}

static void	change_env(t_parsedata *data, t_list *env)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->str[i])
	{
		if (data->str[i] == '$')
		{
			i++;
			if (ft_isalpha(data->str[i]) || data->str[i] == '_'
				|| data->str[i] == '?')
				change_default(data, &i, &j, env);
			else
				data->env_str[j++] = '$';
		}
		else if (ft_isquote(data->str[i]) == 2)
			env_in_quote(data, &i, &j, env);
		else if (ft_isquote(data->str[i]) == 1)
			no_change_vlaue(data, &i, &j);
		else
			data->env_str[j++] = data->str[i++];
	}
}

void	parsing_env(t_parsedata *data, t_list *env)
{
	size_t	total_len;

	if (data->str == NULL)
		return ;
	total_len = ft_strlen(data->str);
	count_total_len(data->str, env, &total_len);
	data->env_str = (char *)ft_malloc_err(sizeof(char) * (total_len + 1));
	data->env_str[total_len] = '\0';
	change_env(data, env);
}
