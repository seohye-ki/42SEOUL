/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:21:29 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/26 17:48:41 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	find_env_name(char *content, char *name, int only_with_eq_flag)
{
	int	name_len;

	name_len = ft_strlen(name);
	if (only_with_eq_flag == 1)
	{
		if (ft_strncmp(content, name, name_len) == 0 \
			&& (content)[name_len] == '=')
			return (1);
	}
	else
	{
		if (ft_memcmp(content, name, name_len + 1) == 0 \
			|| (ft_memcmp(content, name, name_len) == 0 \
			&& content[name_len] == '='))
			return (1);
	}
	return (0);
}

t_list	*envp_to_lst(char **envp)
{
	t_list	*env;
	t_list	*new;
	int		i;

	i = 0;
	if (envp == NULL)
		return (NULL);
	env = ft_lstnew(ft_strdup_err("?=0"));
	if (env == NULL)
		error_exit("malloc failed", 0, 0, EXIT_FAILURE);
	while (envp[i])
	{
		new = ft_lstnew(ft_strdup_err(envp[i]));
		if (env == NULL)
			error_exit("malloc failed", 0, 0, EXIT_FAILURE);
		ft_lstadd_back(&env, new);
		i++;
	}
	return (env);
}

char	*find_env(char *name, t_list *env)
{
	char	*value;
	t_list	*cur;
	size_t	name_len;

	value = NULL;
	cur = env;
	if (name == NULL || env == NULL)
		return (NULL);
	name_len = ft_strlen(name);
	while (cur != NULL)
	{
		if (find_env_name((char *)cur->content, name, 1))
		{
			value = ft_strdup_err(&((char *)cur->content)[name_len + 1]);
			return (value);
		}
		cur = cur->next;
	}
	if (value == NULL)
		value = ft_malloc_err(1);
	value[0] = '\0';
	return (value);
}

void	no_value_update_env(char *name, t_list *env)
{
	t_list	*cur;
	t_list	*new;

	cur = env;
	if (name == NULL || env == NULL)
		return ;
	while (cur != NULL)
	{
		if (find_env_name((char *)cur->content, name, 0))
			return ;
		cur = cur->next;
	}
	new = ft_lstnew(ft_strdup_err(name));
	if (new == NULL)
		error_exit("malloc failed", 0, 0, EXIT_FAILURE);
	ft_lstadd_back(&env, new);
}

void	update_env(char *name, char *value, t_list *env)
{
	t_list	*cur;
	t_list	*new;

	cur = env;
	if (name == NULL || env == NULL)
		return ;
	while (cur != NULL)
	{
		if (find_env_name((char *)cur->content, name, 0))
		{
			free(cur->content);
			cur->content = ft_strjoin_sep(name, value, "=");
			return ;
		}
		cur = cur->next;
	}
	new = ft_lstnew(ft_strjoin_sep(name, value, "="));
	if (new == NULL)
		error_exit("malloc failed", 0, 0, EXIT_FAILURE);
	ft_lstadd_back(&env, new);
}
