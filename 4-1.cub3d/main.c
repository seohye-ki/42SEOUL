/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:25 by seohyeki          #+#    #+#             */
/*   Updated: 2024/05/06 15:16:17 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "ray.h"
#include "util.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_mlxdata	mlxdata;

	mlxdata.map = NULL;
	parsing(argc, argv, &mlxdata);
	ray_loop(mlxdata.map, &mlxdata, &mlxdata.player);
	mlx_hook(mlxdata.ptr.win_ptr, 17, 0, win_close, &mlxdata.ptr);
	mlx_hook(mlxdata.ptr.win_ptr, 2, 1, press_handler, &mlxdata.ptr);
	mlx_hook(mlxdata.ptr.win_ptr, 3, 2, release_handler, &mlxdata.ptr);
	mlx_loop_hook(mlxdata.ptr.mlx_ptr, render_screen, &mlxdata);
	mlx_loop(mlxdata.ptr.mlx_ptr);
	return (0);
}
