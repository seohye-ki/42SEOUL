/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:35:56 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/15 16:12:04 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_fdnode(t_fdlist **fdlst, t_data *data, int fd)
{
	t_fdlist	*curr;
	t_fdlist	*previous;

	free(data->buf);
	if (*fdlst == NULL)
		return ;
	curr = *fdlst;
	if (curr->fd == fd)
	{
		*fdlst = curr->next;
		free(curr);
		return ;
	}
	while (curr != NULL)
	{
		if (curr->fd == fd)
		{
			previous->next = curr->next;
			free(curr);
			return ;
		}
		previous = curr;
		curr = curr->next;
	}
}

static int	chk_backup(t_fdlist **fdlst, t_data *data, int fd)
{
	t_fdlist	*previous;
	t_fdlist	*curr;

	data->line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (data->line == NULL)
		return (0);
	data->line[0] = '\0';
	curr = *fdlst;
	while (curr != NULL)
	{
		if (curr->fd == fd)
		{
			ft_strcat(data->line, curr->content);
			return (1);
		}
		previous = curr;
		curr = curr->next;
	}
	if (add_newnode(&previous, fdlst, fd) == 0)
	{
		free(data->line);
		return (0);
	}
	return (1);
}

static int	read_file(t_data *data, int fd)
{
	size_t	n;

	n = 1;
	while (ft_find_nl(data->line, data) == 0)
	{
		data->read_size = read(fd, data->buf, BUFFER_SIZE);
		if (data->read_size <= 0)
			return (0);
		data->buf[data->read_size] = '\0';
		if (data->len + data->read_size >= BUFFER_SIZE * n)
		{
			n *= 2;
			data->line = ft_re_malloc(data->line, BUFFER_SIZE * n);
			if (data->line == NULL)
				return (0);
		}
		ft_strcat(data->line, data->buf);
	}
	if (data->line[data->pos] == '\n')
		data->pos++;
	return (1);
}

static void	save_backup(t_fdlist **fdlst, t_data *data, int fd)
{
	t_fdlist	*curr;

	curr = *fdlst;
	while (curr != NULL)
	{
		if (curr->fd == fd)
		{
			curr->content[0] = '\0';
			ft_strcat(curr->content, &(data->line[data->pos]));
			data->line = ft_re_malloc(data->line, data->pos);
			if (data->line == NULL || curr->content[0] == '\0')
			{
				free_fdnode(fdlst, data, fd);
				return ;
			}
			free(data->buf);
			return ;
		}
		curr = curr->next;
	}
	free(data->buf);
	return ;
}

char	*get_next_line(int fd)
{
	static t_fdlist	*fdlst;
	t_data			data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data.buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (data.buf == NULL || chk_backup(&fdlst, &data, fd) == 0)
	{
		free_fdnode(&fdlst, &data, fd);
		return (NULL);
	}
	if (read_file(&data, fd) == 0)
	{
		free_fdnode(&fdlst, &data, fd);
		if (data.read_size == 0 && data.line[0] != '\0')
		{
			data.line = ft_re_malloc(data.line, data.pos);
			return (data.line);
		}
		free(data.line);
		return (NULL);
	}
	save_backup(&fdlst, &data, fd);
	return (data.line);
}
