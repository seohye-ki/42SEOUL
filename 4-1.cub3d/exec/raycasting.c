/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:31:26 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/03 16:54:53 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "util.h"
#include "mlx.h"
#include <math.h>

static void	init_step(t_ray *ray, t_player *player)
{
	ray->map_x = (int)(player->pos_x);
	ray->map_y = (int)(player->pos_y);
	ray->delta_x = fabs(1 / ray->raydir_x);
	ray->delta_y = fabs(1 / ray->raydir_y);
	if (ray->raydir_x >= 0)
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1 - player->pos_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = -1;
		ray->side_x = (player->pos_x - ray->map_x) * ray->delta_x;
	}
	if (ray->raydir_y >= 0)
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1 - player->pos_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = -1;
		ray->side_y = (player->pos_y - ray->map_y) * ray->delta_y;
	}
}

static void	calculate_dda(char **map, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->hit_side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->hit_side = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void	calculate_walldist_n_wallx(t_ray *ray, t_player *player)
{
	double	diff;
	double	wall_x;

	if (ray->hit_side == 0)
	{
		diff = ray->map_x - player->pos_x + (1 - ray->step_x) / 2;
		ray->wall_dist = diff / ray->raydir_x;
		wall_x = player->pos_y + ray->wall_dist * ray->raydir_y;
	}
	else
	{
		diff = ray->map_y - player->pos_y + (1 - ray->step_y) / 2;
		ray->wall_dist = diff / ray->raydir_y;
		wall_x = player->pos_x + ray->wall_dist * ray->raydir_x;
	}
	wall_x -= floor(wall_x);
	ray->texture_x = (int)(wall_x * (double)IMG_W);
	if (ray->raydir_y > 0 && ray->hit_side == 1)
		ray->texture_x = IMG_W - 1 - ray->texture_x;
	if (ray->raydir_x < 0 && ray->hit_side == 0)
		ray->texture_x = IMG_W - 1 - ray->texture_x;
}

static void	calculate_wall_height(t_ray *ray)
{
	ray->height = (int)(WIN_H / ray->wall_dist);
	if (ray->height > WIN_H)
	{
		ray->draw_start = 0;
		ray->draw_end = WIN_H - 1;
	}
	else
	{
		ray->draw_start = WIN_H / 2 - ray->height / 2;
		ray->draw_end = WIN_H / 2 + ray->height / 2;
	}
}

void	ray_loop(char **map, t_mlxdata *mlxdata, t_player *player)
{
	t_ray		ray;
	t_render	screen;
	int			i;
	double		cam_x;

	init_screen(&screen, &mlxdata->ptr);
	i = 0;
	while (i < WIN_W)
	{
		cam_x = 2 * i / (double)WIN_W - 1;
		ray.raydir_x = player->dir_x + player->plane_x * cam_x;
		ray.raydir_y = player->dir_y + player->plane_y * cam_x;
		init_step(&ray, player);
		calculate_dda(map, &ray);
		calculate_walldist_n_wallx(&ray, player);
		calculate_wall_height(&ray);
		choose_texture(&ray);
		draw_line(i, &mlxdata->img, &ray, &screen);
		i++;
	}
	put_image(&mlxdata->ptr, screen.img, 0, 0);
	mlx_destroy_image(mlxdata->ptr.mlx_ptr, screen.img);
}
