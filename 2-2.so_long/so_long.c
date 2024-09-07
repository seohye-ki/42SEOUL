/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:36:50 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/20 13:06:12 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char		*name;
	t_game		game;

	name = "I'm ggoggo";
	if (argc == 2)
	{
		if (!valid_file(argv[1]))
			print_error();
		read_map(argv[1], &game);
		if (!check_valid_map(&game) || !check_valid_path(game.map, &game))
			print_error();
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.wid * 64, game.hei * 64, name);
		game.move = 0;
		set_img_ptr(&game);
		put_img_win(&game);
		mlx_hook(game.win, 2, 0, &press_key, &game);
		mlx_hook(game.win, 17, 0, &close_win, &game);
		mlx_loop(game.mlx);
	}
	else
		print_error();
	return (0);
}
