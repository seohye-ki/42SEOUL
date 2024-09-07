/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:56:33 by seohyeki          #+#    #+#             */
/*   Updated: 2024/05/05 15:23:45 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

void	check_map_valid(t_list *map)
{
	int	player_flag;

	player_flag = 0;
	while (map)
	{
		if (is_not_element(map->content, &player_flag))
			error_exit("Invalid map.");
		map = map->next;
	}
	if (player_flag == 0)
		error_exit("Invalid map.");
}

void	check_surrounded_wall(char **map, size_t col, size_t row)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || is_palyer_pos(map[i][j]))
			{
				if (i == 0 || i == (row - 1) || j == 0 || j == (col - 1))
					error_exit("Invalid map.");
				else if (map[i + 1][j] == ' ' || map[i - 1][j] == ' '
					|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					error_exit("Invalid map.");
				else if (map[i + 1][j - 1] == ' ' || map[i + 1][j + 1] == ' '
					|| map[i - 1][j - 1] == ' ' || map[i - 1][j + 1] == ' ')
					error_exit("Invalid map.");
			}
			j++;
		}
		i++;
	}
}
