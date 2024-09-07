/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:44:17 by sumilee           #+#    #+#             */
/*   Updated: 2024/02/07 21:46:26 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*fd_scan(t_lst **fdlst, int fd)
{
	t_lst	*cur;
	t_lst	*new;

	cur = *fdlst;
	while (cur != NULL && cur->fd != fd)
		cur = cur->next;
	if (cur != NULL)
		return (cur);
	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = NULL;
	if (*fdlst != NULL)
	{
		cur = *fdlst;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	else
		*fdlst = new;
	return (new);
}

int	first_str(t_lst *fdptr, t_data *data, int fd)
{
	ssize_t	read_size;

	data->alloc_len = 0;
	data->n = 1;
	if (fdptr->str == NULL)
	{
		read_size = read(fd, data->buff, BUFFER_SIZE);
		if (read_size <= 0)
			return (0);
		data->buff[read_size] = '\0';
		fdptr->str = ft_strdup_gnl(data->buff, 0);
		if (fdptr->str == NULL)
			return (0);
	}
	while (fdptr->str[data->alloc_len])
		data->alloc_len++;
	return (1);
}

int	read_loop(t_lst *fdptr, t_data *data, int fd)
{
	size_t	i;
	ssize_t	read_size;

	i = 0;
	data->len = 0;
	while (fdptr->str != NULL)
	{
		while (fdptr->str[i] != '\0')
		{
			data->len++;
			if (fdptr->str[i] == '\n')
				return (1);
			i++;
		}
		read_size = read(fd, data->buff, BUFFER_SIZE);
		if (read_size < 0)
			return (0);
		if (read_size == 0)
			return (1);
		data->buff[read_size] = '\0';
		if (change_malloc(fdptr, data, read_size, 0) == 0)
			return (0);
		ft_strcat(fdptr->str, data->buff);
	}
	return (1);
}

int	join(t_lst *fdptr, t_data *data, int i, int j)
{
	data->ret = (char *)malloc(sizeof(char) * (data->len + 1));
	if (data->ret == NULL)
		return (0);
	while (fdptr->str[++j] != '\0')
	{
		data->ret[++i] = fdptr->str[j];
		if (fdptr->str[j] == '\n')
		{
			if (fdptr->str[j + 1] != '\0')
			{
				data->ret[i + 1] = '\0';
				if (change_malloc(fdptr, data, -1, j + 1) == 0)
				{
					free(data->ret);
					return (0);
				}
				return (1);
			}
			break ;
		}
	}
	data->ret[i + 1] = '\0';
	free(fdptr->str);
	fdptr->str = NULL;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_lst	*fdlst;
	t_lst			*fdptr;
	t_data			data;

	data.buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	fdptr = fd_scan(&fdlst, fd);
	if (data.buff == NULL || fdptr == NULL || \
		first_str(fdptr, &data, fd) == 0 || \
		read_loop(fdptr, &data, fd) == 0 || join(fdptr, &data, -1, -1) == 0)
	{
		if (fdlst != NULL)
			fdnode_del(&fdlst, 1, fd);
		if (data.buff != NULL)
			free(data.buff);
		return (NULL);
	}
	if (fdlst != NULL)
		fdnode_del(&fdlst, 0, fd);
	free(data.buff);
	return (data.ret);
}
