/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:22:28 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/03 10:54:40 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"
#include "mlx.h"

static char	init_player_info_loop(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_palyer_pos(map[i][j]))
			{
				player->pos_x = j + 0.5;
				player->pos_y = i + 0.5;
				return (map[i][j]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_player_info(char **map, t_player *player)
{
	char	c;

	ft_memset(player, 0, sizeof(int) * 6);
	c = init_player_info_loop(map, player);
	if (c == 'N')
	{
		player->dir_y = -1;
		player->plane_x = PLANE;
	}
	else if (c == 'S')
	{
		player->dir_y = 1;
		player->plane_x = -1 * PLANE;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->plane_y = PLANE;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->plane_y = -1 * PLANE;
	}
}

void	init_mlx_data(t_mlxdata *mlxdata, char *program_name)
{
	mlxdata->ptr.mlx_ptr = mlx_init();
	if (mlxdata->ptr.mlx_ptr == NULL)
		error_exit("Mlx init failed.");
	mlxdata->ptr.win_ptr = mlx_new_window(mlxdata->ptr.mlx_ptr, \
									WIN_W, WIN_H, program_name);
	if (mlxdata->ptr.win_ptr == NULL)
		error_exit("New mlx window creation failed.");
	ft_memset(mlxdata->key_flag, 0, sizeof(int) * 6);
}
