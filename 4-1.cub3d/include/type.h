/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:11:20 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/03 10:53:59 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# define PLANE 1
# define IMG_H 500
# define IMG_W 500
# define WIN_W 1984
# define WIN_H 1024
# define WALL_NO 0
# define WALL_SO 1
# define WALL_WE 2
# define WALL_EA 3
# define BUTTON_DESTROY 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LE 123
# define KEY_RI 124

typedef struct s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ptr;

typedef struct s_render
{
	void	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
}				t_render;

typedef struct s_map_info
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}				t_map_info;

typedef struct s_img
{
	int		img_h;
	int		img_w;
	void	*texture[4];
	int		fl_color;
	int		cl_color;
}				t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_mlxdata
{
	t_ptr		ptr;
	t_img		img;
	t_player	player;
	char		**map;
	int			key_flag[6];
}				t_mlxdata;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	double	raydir_x;
	double	raydir_y;
	double	step_x;
	double	step_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		hit_side;
	double	wall_dist;
	int		wall_type;
	double	texture_x;
	int		height;
	int		draw_start;
	int		draw_end;
}				t_ray;

#endif