/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:00 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/03 10:50:23 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "type.h"

void	ray_loop(char **map, t_mlxdata *mlxdata, t_player *player);

void	init_screen(t_render *screen, t_ptr *ptr);
void	choose_texture(t_ray *ray);
void	draw_line(int line, t_img *img, t_ray *ray, t_render *render);

#endif