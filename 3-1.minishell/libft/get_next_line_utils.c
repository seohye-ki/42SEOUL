/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:44:19 by sumilee           #+#    #+#             */
/*   Updated: 2024/02/07 21:46:40 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_gnl(const char *src, size_t index)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (len - index == 0)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (len - index + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len - index)
	{
		dest[i] = src[i + index];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char const *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void	clear(t_lst **head)
{
	t_lst	*cur;
	t_lst	*tmp;

	cur = *head;
	while (cur != NULL)
	{
		if (cur->str != NULL)
		{
			free(cur->str);
			cur->str = NULL;
		}
		tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
	*head = NULL;
	head = NULL;
	return ;
}

int	change_malloc(t_lst *fdptr, t_data *data, int read_size, int index)
{
	char	*tmp;

	if (read_size == -1 || data->alloc_len < data->len + read_size)
	{
		tmp = ft_strdup_gnl(fdptr->str, index);
		if (tmp == NULL)
			return (0);
		free(fdptr->str);
		if (read_size != -1)
			data->alloc_len += BUFFER_SIZE * data->n;
		else
			data->alloc_len = data->alloc_len - data->len;
		fdptr->str = (char *)malloc(sizeof(char) * (data->alloc_len + 1));
		if (fdptr->str == NULL)
		{
			free(tmp);
			return (0);
		}
		fdptr->str[0] = '\0';
		ft_strcat(fdptr->str, tmp);
		free(tmp);
		tmp = NULL;
		data->n *= 2;
	}
	return (1);
}

void	fdnode_del(t_lst **fdlst, int indicator, int fd)
{
	t_lst	*curr;
	t_lst	*del;

	curr = *fdlst;
	if (curr->str == NULL || (indicator == 1 && curr->fd == fd))
	{
		if (curr->str != NULL)
			free(curr->str);
		*fdlst = curr->next;
		free(curr);
		return ;
	}
	while (curr->next != NULL)
	{
		if (curr->next->str == NULL || (indicator == 1 && curr->fd == fd))
		{
			if (curr->next->str != NULL)
				free(curr->next->str);
			del = curr->next;
			curr->next = curr->next->next;
			free(del);
			return ;
		}
		curr = curr->next;
	}
}
