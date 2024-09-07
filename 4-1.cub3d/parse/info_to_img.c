/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:59:10 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/08 12:32:08 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"
#include "mlx.h"

static void	count_comma(char *code)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (code[i])
	{
		if (code[i] == ',')
			cnt++;
		i++;
	}
	if (cnt != 2)
		error_exit("Wrong color information.");
}

static void	convert_color(char *code, int *color)
{
	char	**split;
	int		temp;
	int		result;
	int		i;

	count_comma(code);
	split = ft_split(code, ',');
	if (split == NULL)
		error_exit("Malloc failed.");
	if (split[0] == NULL)
		error_exit("Wrong color information.");
	i = 0;
	result = 0;
	while (i < 3 && split[i])
	{
		temp = ft_atoi_err(split[i]);
		result |= temp << ((2 - i) * 8);
		i++;
	}
	if (i != 3 || split[i] != NULL)
		error_exit("Wrong color information.");
	*color = result;
	free_arr(split);
}

void	info_to_img(t_ptr *ptr, t_map_info *info, t_img *img)
{
	img->img_h = IMG_H;
	img->img_w = IMG_W;
	img->texture[WALL_NO] = mlx_xpm_file_to_image(ptr->mlx_ptr, info->north, \
									&img->img_w, &img->img_h);
	img->texture[WALL_SO] = mlx_xpm_file_to_image(ptr->mlx_ptr, info->south, \
									&img->img_w, &img->img_h);
	img->texture[WALL_WE] = mlx_xpm_file_to_image(ptr->mlx_ptr, info->west, \
									&img->img_w, &img->img_h);
	img->texture[WALL_EA] = mlx_xpm_file_to_image(ptr->mlx_ptr, info->east, \
									&img->img_w, &img->img_h);
	if (img->texture[0] == NULL || img->texture[1] == NULL || \
		img->texture[2] == NULL || img->texture[3] == NULL)
		error_exit("Graphic image error.");
	convert_color(info->floor, &img->fl_color);
	convert_color(info->ceiling, &img->cl_color);
	free(info->north);
	free(info->south);
	free(info->west);
	free(info->east);
	free(info->floor);
	free(info->ceiling);
}
