/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:56 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/12 17:02:33 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_nl(const char *s, t_data *data)
{
	data->len = 0;
	while (data->line[data->len] != '\0')
		data->len++;
	data->pos = 0;
	while (s[data->pos] != '\0')
	{
		if (s[data->pos] == '\n')
			return (1);
		data->pos++;
	}
	return (0);
}

void	ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
}

char	*ft_re_malloc(char *origin, size_t size)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
	{
		free(origin);
		return (NULL);
	}
	new[size] = '\0';
	i = 0;
	while (origin[i] != '\0' && i < size)
	{
		new[i] = origin[i];
		i++;
	}
	new[i] = '\0';
	free(origin);
	return (new);
}

int	add_newnode(t_fdlist **previous, t_fdlist **fdlst, int fd)
{
	t_fdlist	*newnode;

	newnode = (t_fdlist *)malloc(sizeof(t_fdlist));
	if (newnode == NULL)
		return (0);
	newnode->fd = fd;
	newnode->content[BUFFER_SIZE] = '\0';
	newnode->next = 0;
	if (*fdlst == NULL)
		*fdlst = newnode;
	else
		(*previous)->next = newnode;
	return (1);
}
