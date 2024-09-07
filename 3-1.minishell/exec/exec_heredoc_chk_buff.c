/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc_chk_buff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:44:33 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/28 16:56:01 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

static void	cnt_len(char *buff, t_list *env, size_t *len, int *flag)
{
	size_t	i;
	char	*name;
	char	*value;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '$')
		{
			i++;
			if (ft_isalpha(buff[i]) || buff[i] == '_' || buff[i] == '?')
			{
				(*flag) = 1;
				name = get_env_name(buff + i);
				value = find_env(name, env);
				len = len - (ft_strlen(name) + 1) + ft_strlen(value);
				free(name);
				free(value);
			}
		}
		else
			i++;
	}
}

static void	change_loop(char *new, char *name, char *value, size_t *j)
{
	size_t	k;

	k = 0;
	while (value[k])
		new[(*j)++] = value[k++];
	free(name);
	free(value);
}

static void	replace_env(char *buff, char *new, t_list *env)
{
	size_t	i;
	size_t	j;
	char	*name;
	char	*value;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == '$')
		{
			i++;
			if (ft_isalpha(buff[i]) || buff[i] == '_' || buff[i] == '?')
			{
				name = get_env_name(buff + i);
				value = find_env(name, env);
				i += ft_strlen(name);
				change_loop(new, name, value, &j);
			}
			else
				buff[j++] = '$';
		}
		else
			new[j++] = buff[i++];
	}
}

char	*chk_buff(char *buff, t_list *env)
{
	size_t	len;
	int		flag;
	char	*new;

	flag = 0;
	len = ft_strlen(buff);
	cnt_len(buff, env, &len, &flag);
	if (flag)
	{
		new = (char *)ft_malloc_err(sizeof(size_t) * (len + 1));
		new[len] = '\0';
		replace_env(buff, new, env);
		free(buff);
		return (new);
	}
	return (buff);
}
