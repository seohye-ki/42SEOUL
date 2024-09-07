/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:11 by sumilee           #+#    #+#             */
/*   Updated: 2023/10/09 13:00:49 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*tmp;

	if (*lst != NULL)
	{
		cur = *lst;
		while (cur != NULL)
		{
			tmp = cur;
			cur = cur->next;
			ft_lstdelone(tmp, del);
		}
		*lst = NULL;
	}
}
