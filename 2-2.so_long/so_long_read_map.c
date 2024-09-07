/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:07:50 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 16:27:39 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_strlen_no_nl(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

static void	ft_strcat_no_nl(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\n' && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
}

static char	*ft_strjoin_realloc(char *dest, char *src)
{
	size_t	dest_len;
	size_t	src_len;
	char	*new;

	dest_len = ft_strlen_no_nl(dest);
	src_len = ft_strlen_no_nl(src);
	new = (char *)malloc(sizeof(char) * (dest_len + src_len + 1));
	if (new == NULL)
		exit(1);
	new[0] = '\0';
	ft_strcat_no_nl(new, dest);
	ft_strcat_no_nl(new, src);
	free(dest);
	free(src);
	return (new);
}

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_error();
	line = get_next_line(fd);
	if (line == NULL)
		print_error();
	game->hei = 0;
	game->wid = ft_strlen_no_nl(line);
	game->map = line;
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
		{
			if (ft_strlen_no_nl(line) != game->wid)
				print_error();
			game->map = ft_strjoin_realloc(game->map, line);
		}
	}
	close(fd);
}
