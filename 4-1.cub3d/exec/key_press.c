/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:29:54 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/06 22:26:20 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "util.h"
#include <math.h>

int	press_handler(int key, t_mlxdata *data)
{
	if (key == KEY_ESC)
		win_close(&data->ptr);
	else if (key == KEY_W)
		data->key_flag[0] = 1;
	else if (key == KEY_A)
		data->key_flag[1] = 1;
	else if (key == KEY_S)
		data->key_flag[2] = 1;
	else if (key == KEY_D)
		data->key_flag[3] = 1;
	else if (key == KEY_RI)
		data->key_flag[4] = 1;
	else if (key == KEY_LE)
		data->key_flag[5] = 1;
	return (0);
}

int	release_handler(int key, t_mlxdata *data)
{
	if (key == KEY_W)
		data->key_flag[0] = 0;
	else if (key == KEY_A)
		data->key_flag[1] = 0;
	else if (key == KEY_S)
		data->key_flag[2] = 0;
	else if (key == KEY_D)
		data->key_flag[3] = 0;
	else if (key == KEY_RI)
		data->key_flag[4] = 0;
	else if (key == KEY_LE)
		data->key_flag[5] = 0;
	return (0);
}

void	move(char **map, t_player *player, double amount, int direction)
{
	double	move_x;
	double	move_y;
	double	move_for_x;
	double	move_for_y;

	if (direction == 0)
	{
		move_x = player->pos_x + player->dir_x * amount;
		move_y = player->pos_y + player->dir_y * amount;
	}
	else
	{
		move_x = player->pos_x + player->dir_y * amount;
		move_y = player->pos_y + player->dir_x * -1 * amount;
	}
	move_for_x = copysign(0.1, move_x - player->pos_x);
	move_for_y = copysign(0.1, move_y - player->pos_y);
	if (map[(int)(player->pos_y + 0.1)][(int)(move_x + move_for_x)] != '1' \
		&& map[(int)(player->pos_y - 0.1)][(int)(move_x + move_for_x)] != '1')
		player->pos_x = move_x;
	if (map[(int)(move_y + move_for_y)][(int)(player->pos_x + 0.1)] != '1' \
		&& map[(int)(move_y + move_for_y)][(int)(player->pos_x - 0.1)] != '1')
		player->pos_y = move_y;
}

void	rotate(t_player *player, double amount)
{
	double	x;
	double	y;

	x = player->dir_x * cos(amount) - player->dir_y * sin(amount);
	y = player->dir_x * sin(amount) + player->dir_y * cos(amount);
	player->dir_x = x;
	player->dir_y = y;
	x = player->dir_x * cos(M_PI / 2) - player->dir_y * sin(M_PI / 2);
	y = player->dir_x * sin(M_PI / 2) + player->dir_y * cos(M_PI / 2);
	player->plane_x = x;
	player->plane_y = y;
}

int	render_screen(t_mlxdata *data)
{
	double	move_unit;
	double	rotate_unit;

	move_unit = 0.1;
	rotate_unit = 0.03;
	if (data->key_flag[0] == 1)
		move(data->map, &data->player, move_unit, 0);
	if (data->key_flag[1] == 1)
		move(data->map, &data->player, move_unit, 1);
	if (data->key_flag[2] == 1)
		move(data->map, &data->player, -1 * move_unit, 0);
	if (data->key_flag[3] == 1)
		move(data->map, &data->player, -1 * move_unit, 1);
	if (data->key_flag[4] == 1)
		rotate(&data->player, rotate_unit);
	if (data->key_flag[5] == 1)
		rotate(&data->player, -1 * rotate_unit);
	ray_loop(data->map, data, &data->player);
	return (0);
}
