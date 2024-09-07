/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:57:47 by seohyeki          #+#    #+#             */
/*   Updated: 2024/05/03 16:26:55 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

static t_list	*ft_lstlast_prev(t_list *lst)
{
	t_list	*prev;

	prev = NULL;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			prev = lst;
			lst = lst->next;
		}
	}
	return (prev);
}

static void	trim_start_node(t_list **map)
{
	t_list	*tmp;

	while (*map != NULL)
	{
		if (is_emptyline((char *)((*map)->content)))
		{
			tmp = *map;
			*map = (*map)->next;
			ft_lstdelone(tmp, free);
		}
		else
			return ;
	}
}

static void	trim_end_node(t_list **map)
{
	t_list	*head;

	head = *map;
	while (1)
	{
		*map = ft_lstlast_prev(*map);
		if (*map == NULL)
		{
			*map = head;
			return ;
		}
		if (is_emptyline((char *)((*map)->next->content)))
		{
			ft_lstdelone((*map)->next, free);
			(*map)->next = NULL;
			*map = head;
		}
		else
		{
			*map = head;
			return ;
		}
	}
}

static void	delete_newline(t_list **map)
{
	t_list	*head;
	char	*cur;
	size_t	i;

	head = *map;
	while (*map)
	{
		cur = (char *)((*map)->content);
		i = 0;
		while (cur[i] != '\0' && cur[i] != '\n')
			i++;
		if (cur[i] == '\n')
			cur[i] = '\0';
		*map = (*map)->next;
	}
	*map = head;
}

void	ft_lst_trim(t_list **map)
{
	trim_start_node(map);
	if (*map == NULL)
		error_exit("Invalid map.");
	trim_end_node(map);
	delete_newline(map);
}
