/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:18:56 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/26 02:47:27 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "parse.h"

void	free_token(void *token)
{
	t_token	*token_node;

	token_node = (t_token *)token;
	if (token_node != NULL)
	{
		if (token_node->str != NULL)
			free(token_node->str);
		free(token_node);
	}
}

void	free_tokens_in_pipe(void *node)
{
	t_list	*pipe_tokens;

	pipe_tokens = (t_list *)node;
	if (pipe_tokens != NULL)
		ft_lstclear(&pipe_tokens, free_token);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
