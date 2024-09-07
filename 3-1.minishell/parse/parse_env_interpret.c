/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_interpret.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:34:51 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/26 14:51:31 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

char	*get_env_name(char *str)
{
	size_t	i;
	size_t	size;
	char	*name;

	i = 0;
	size = 0;
	if (str[i] == '?')
		size++;
	else
	{
		while (ft_isalnum(str[i]) || str[i] == '_')
		{
			i++;
			size++;
		}
	}
	name = (char *)ft_malloc_err(sizeof(char) * (size + 1));
	name[size] = '\0';
	i = 0;
	while (i < size)
	{
		name[i] = str[i];
		i++;
	}
	return (name);
}

static void	interpret_default(char *s, t_list *env, size_t *len, size_t *i)
{
	char	*name;
	char	*src;
	size_t	meta;
	size_t	index;

	name = get_env_name(s + *i);
	src = find_env(name, env);
	meta = 0;
	index = 0;
	while (src[index])
	{
		if (ft_isquote(src[index]) || ft_ispipe(src[index])
			|| ft_isredi(src[index]))
			meta++;
		index++;
	}
	(*len) = (*len) - (ft_strlen(name) + 1) + ft_strlen(src) + (meta * 2);
	free(name);
	free(src);
}

static size_t	interpret_quote(char *str, t_list *env, size_t *len, size_t *i)
{
	char	*name;
	char	*src;
	size_t	meta;
	size_t	index;

	name = get_env_name(str + *i);
	src = find_env(name, env);
	meta = 0;
	index = 0;
	while (src[index])
	{
		if (ft_isquote(src[index]) || ft_ispipe(src[index])
			|| ft_isredi(src[index]) || ft_isspace(src[index]))
			meta++;
		index++;
	}
	(*len) = (*len) - (ft_strlen(name) + 1) + ft_strlen(src) + (meta * 2);
	free(name);
	free(src);
	return (meta);
}

static void	count_quote_len(char *str, t_list *env, size_t *len, size_t *i)
{
	(*i)++;
	while (ft_isquote(str[*i]) != 2 && str[*i])
	{
		if (str[*i] == '$')
		{
			(*i)++;
			if (ft_isalpha(str[*i]) || str[*i] == '_' || str[*i] == '?')
			{
				if (interpret_quote(str, env, len, i))
					(*len) += 2;
			}
		}
		(*i)++;
	}
	if (str[*i])
		(*i)++;
}

void	count_total_len(char *str, t_list *env, size_t *len)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isquote(str[i]) == 2)
			count_quote_len(str, env, len, &i);
		else if (str[i] == '$')
		{
			i++;
			if (ft_isalpha(str[i]) || str[i] == '_' || str[i] == '?')
				interpret_default(str, env, len, &i);
		}
		else if (ft_isquote(str[i]) == 1)
		{
			i++;
			while (str[i] != '\'' && str[i])
				i++;
			if (str[i])
				i++;
		}
		else
			i++;
	}
}
