/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:23:20 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/26 15:38:02 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"
#include <stdlib.h>

static void	make_token(t_list **head, char *str, int *i, int *cnt)
{
	int		type;
	char	*token_str;
	t_token	*token;
	t_list	*new;

	if (*cnt == 0)
		return ;
	type = check_token_type(str + *i - *cnt);
	token_str = ft_strndup(str + *i - *cnt, *cnt);
	token = (t_token *)ft_malloc_err(sizeof(t_token));
	token->str = token_str;
	token->type = type;
	new = ft_lstnew(token);
	if (new == NULL)
		error_exit("malloc failed", 0, 0, EXIT_FAILURE);
	ft_lstadd_back(head, new);
	(*cnt) = 0;
}

static int	make_pipe_redirect_token(t_list **head, char *str, int *i, int *cnt)
{
	char	c;

	make_token(head, str, i, cnt);
	(*cnt)++;
	if (ft_ispipe(str[*i]))
	{
		(*i)++;
		if (ft_ispipe(str[*i]) || !str[*i])
			return (1);
	}
	else if (ft_isredi(str[*i]))
	{
		c = str[(*i)++];
		if (str[*i] == c)
		{
			(*i)++;
			(*cnt)++;
			if (ft_ispipe(str[*i]) || ft_isredi(str[*i]) || !str[*i])
				return (SYNTAX_ERROR);
		}
		else if (ft_ispipe(str[*i]) || ft_isredi(str[*i]) || !str[*i])
			return (SYNTAX_ERROR);
	}
	make_token(head, str, i, cnt);
	return (0);
}

static int	count_quote(char *str, int *i, int *cnt)
{
	char	c;

	while (ft_isquote(str[*i]))
	{
		c = str[(*i)];
		(*i)++;
		(*cnt)++;
		while (str[*i] != c && str[*i])
		{
			(*i)++;
			(*cnt)++;
		}
		if (str[*i] == '\0')
			return (SYNTAX_ERROR);
		else
		{
			(*i)++;
			(*cnt)++;
		}
	}
	return (0);
}

static int	split_loop(t_list **head, char *str, int *i, int *cnt)
{
	if (ft_ispipe(str[*i]) || ft_isredi(str[*i]))
	{
		if (make_pipe_redirect_token(head, str, i, cnt))
		{
			ft_lstclear(head, free_token);
			return (SYNTAX_ERROR);
		}
	}	
	else if (ft_isquote(str[*i]))
	{
		if (count_quote(str, i, cnt))
		{
			ft_lstclear(head, free_token);
			return (SYNTAX_ERROR);
		}
	}
	return (0);
}

int	split_token(t_list **head, char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			make_token(head, str, &i, &cnt);
			i++;
		}
		else if (ft_isquote(str[i]) || ft_ispipe(str[i]) || ft_isredi(str[i]))
		{
			if (split_loop(head, str, &i, &cnt))
				return (1);
		}
		else
		{
			i++;
			cnt++;
		}
	}
	make_token(head, str, &i, &cnt);
	return (0);
}
