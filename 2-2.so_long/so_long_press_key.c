/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_press_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:41:26 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 16:26:10 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_game *game, int move)
{
	int	i;

	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i + move] == 'C')
		game->c_cnt++;
	if (game->map[i + move] == 'E' && game->c_cnt == game->c_num)
	{
		game->move++;
		ft_printf("%d\n", game->move);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (game->map[i + move] != 'E' && game->map[i + move] != '1')
	{
		game->map[i] = '0';
		game->map[i + move] = 'P';
		game->move++;
		ft_printf("%d\n", game->move);
		put_img_win(game);
	}
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == 13)
		move(game, (game->wid * -1));
	else if (keycode == 0)
		move(game, -1);
	else if (keycode == 1)
		move(game, game->wid);
	else if (keycode == 2)
		move(game, 1);
	else if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}
