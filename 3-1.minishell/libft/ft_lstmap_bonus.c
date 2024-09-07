/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:40 by sumilee           #+#    #+#             */
/*   Updated: 2023/10/10 14:48:19 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	clear_all(t_list *newlst, t_list **content, void (*del)(void *))
{
	ft_lstclear(&newlst, del);
	del(*content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*newlst;
	t_list	*nxtlst;
	t_list	*content;

	if (lst != NULL)
	{
		cur = lst;
		content = f(cur->content);
		newlst = ft_lstnew(content);
		if (newlst == NULL)
			clear_all(newlst, &content, del);
		while (newlst != NULL && cur->next != NULL)
		{
			cur = cur->next;
			content = f(cur->content);
			nxtlst = ft_lstnew(content);
			if (nxtlst == NULL)
				clear_all(nxtlst, &content, del);
			ft_lstadd_back(&newlst, nxtlst);
		}
		return (newlst);
	}
	return (NULL);
}
