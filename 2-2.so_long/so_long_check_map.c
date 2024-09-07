/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:12:10 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 17:48:52 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	surrounded_by_wall(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		if (j == 0 && game->map[i] != '1')
			return (0);
		else if (j == (game->hei - 1) && game->map[i] != '1')
			return (0);
		else if (i % game->wid == 0 && game->map[i] != '1')
			return (0);
		else if ((i % game->wid) == (game->wid - 1) && game->map[i] != '1')
			return (0);
		i++;
		if (i % game->wid == 0)
			j++;
	}
	return (1);
}

static int	count_c_p_e(t_game *game)
{
	size_t	i;
	int		e_num;
	int		p_num;

	i = 0;
	e_num = 0;
	p_num = 0;
	game->c_cnt = 0;
	game->c_num = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'C')
			game->c_num++;
		else if (game->map[i] == 'P')
			p_num++;
		else if (game->map[i] == 'E')
			e_num++;
		else if (game->map[i] != '0' && game->map[i] != '1')
			return (0);
		i++;
	}
	if (game->c_num < 1 || p_num != 1 || e_num != 1)
		return (0);
	return (1);
}

int	check_valid_map(t_game *game)
{
	if (game->wid < 3 || game->hei < 3)
		return (0);
	if (!surrounded_by_wall(game))
		return (0);
	if (!count_c_p_e(game))
		return (0);
	return (1);
}
