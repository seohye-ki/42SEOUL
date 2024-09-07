/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:28:08 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/16 15:15:48 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img_ptr(t_game *game)
{
	int	wid;
	int	hei;

	game->move = 0;
	game->img_p = mlx_xpm_file_to_image(game->mlx, "img_p.xpm", &wid, &hei);
	game->img_p2 = mlx_xpm_file_to_image(game->mlx, "img_p2.xpm", &wid, &hei);
	game->img_t = mlx_xpm_file_to_image(game->mlx, "img_t.xpm", &wid, &hei);
	game->img_w = mlx_xpm_file_to_image(game->mlx, "img_w.xpm", &wid, &hei);
	game->img_e = mlx_xpm_file_to_image(game->mlx, "img_e.xpm", &wid, &hei);
	game->img_c = mlx_xpm_file_to_image(game->mlx, "img_c.xpm", &wid, &hei);
}

void	put_move_cnt(t_game *game)
{
	char	*move_cnt;

	move_cnt = ft_itoa(game->move);
	mlx_string_put(game->mlx, game->win, 26, 27, 0xFF0000, move_cnt);
	free(move_cnt);
}

void	put_player_img(size_t x, size_t y, t_game *g)
{
	if (g->move % 2 == 0)
		mlx_put_image_to_window(g->mlx, g->win, g->img_p, x * 64, y * 64);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img_p2, x * 64, y * 64);
}

void	put_img_win(t_game *g)
{
	size_t	x;
	size_t	y;
	int		n;

	n = 64;
	y = 0;
	while (y < g->hei)
	{
		x = 0;
		while (x < g->wid)
		{
			mlx_put_image_to_window(g->mlx, g->win, g->img_t, x * n, y * n);
			if (g->map[x + (y * g->wid)] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->img_w, x * n, y * n);
			else if (g->map[x + (y * g->wid)] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->img_c, x * n, y * n);
			else if (g->map[x + (y * g->wid)] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->img_e, x * n, y * n);
			else if (g->map[x + (y * g->wid)] == 'P')
				put_player_img(x, y, g);
			x++;
		}
		y++;
	}
	put_move_cnt(g);
}
