/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:41:14 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/29 20:22:08 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

static void	make_map_lst(t_list **map, int fd)
{
	char	*map_str;
	t_list	*new;

	while (1)
	{
		map_str = get_next_line(fd);
		if (map_str == NULL)
			break ;
		new = ft_lstnew(map_str);
		if (new == NULL)
			error_exit("malloc failed");
		ft_lstadd_back(map, new);
	}
}

static void	count_mapsize(t_list *map, size_t *col, size_t *row)
{
	size_t	len;

	*col = 0;
	*row = 0;
	while (map)
	{
		(*row)++;
		len = ft_strlen(map->content);
		if (len > *col)
			*col = len;
		map = map->next;
	}
}

static char	**make_map_arr(t_list *maplst, size_t *col, size_t *row)
{
	size_t	i;
	size_t	j;
	char	**map;

	count_mapsize(maplst, col, row);
	map = ft_malloc_err(sizeof(char *) * (*row + 1));
	map[*row] = NULL;
	i = 0;
	while (maplst)
	{
		map[i] = ft_malloc_err(sizeof(char) * (*col + 1));
		ft_memset(map[i], 32, *col + 1);
		map[i][*col] = 0;
		j = 0;
		while (((char *)(maplst->content))[j])
		{
			map[i][j] = ((char *)(maplst->content))[j];
			j++;
		}
		i++;
		maplst = maplst->next;
	}
	return (map);
}

void	parse_map(int fd, char ***map)
{
	t_list	*maplst;
	size_t	col;
	size_t	row;

	maplst = NULL;
	make_map_lst(&maplst, fd);
	ft_lst_trim(&maplst);
	check_map_valid(maplst);
	*map = make_map_arr(maplst, &col, &row);
	check_surrounded_wall(*map, col, row);
	ft_lstclear(&maplst, free);
}
