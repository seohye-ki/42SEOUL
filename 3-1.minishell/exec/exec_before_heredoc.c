/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_before_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:00:32 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/26 02:41:14 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parse.h"
#include "util.h"

static char	*ft_strjoin_err(char const *s1, char const *s2)
{
	size_t	strlen;
	char	*arr;

	strlen = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (strlen + 1));
	if (arr == NULL)
		error_exit("malloc failed", 0, 0, EXIT_FAILURE);
	arr[0] = '\0';
	ft_strcat(arr, s1);
	ft_strcat(arr, s2);
	return (arr);
}

static char	**parse_delimiter(t_list *pipe, int doc_cnt)
{
	t_list	*pp_cur;
	t_list	*tk_cur;
	char	**arr;
	int		i;

	arr = ft_malloc_err(sizeof(char *) * doc_cnt + 1);
	arr[doc_cnt] = 0;
	pp_cur = pipe;
	i = 0;
	while (pp_cur != NULL)
	{
		tk_cur = pp_cur->content;
		while (tk_cur != NULL)
		{
			if (((t_token *)tk_cur->content)->type == TYPE_HEREDOC)
			{
				arr[i] = ft_strdup_err(((t_token *)tk_cur->content)->str);
				i++;
			}
			tk_cur = tk_cur->next;
		}
		pp_cur = pp_cur->next;
	}
	return (arr);
}

static char	*create_tmpname(int i)
{
	char	*name;
	char	*tmp;
	char	*num;

	num = ft_itoa_err(i);
	name = ft_strjoin_err("./.", num);
	while (access(name, F_OK) == 0)
	{
		tmp = name;
		name = ft_strjoin_err(tmp, num);
		free(tmp);
	}
	free(num);
	return (name);
}

void	before_heredoc(t_execdata *data)
{
	int	i;

	i = 0;
	if (data->doc_cnt == 0)
	{
		data->eof_arr = NULL;
		data->file_arr = NULL;
		return ;
	}
	data->eof_arr = parse_delimiter(data->pipe, data->doc_cnt);
	data->file_arr = ft_malloc_err(sizeof(char *) * data->doc_cnt + 1);
	data->file_arr[data->doc_cnt] = 0;
	while (i < data->doc_cnt)
	{
		data->file_arr[i] = create_tmpname(i);
		i++;
	}
}
