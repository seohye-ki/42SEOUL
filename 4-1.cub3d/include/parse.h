/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:34:34 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 22:05:01 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "type.h"

void	parsing(int argc, char **argv, t_mlxdata *mlxdata);

/*parse_map*/
void	parse_map_info(int fd, t_map_info *info);

/*parse_map*/
void	parse_map(int fd, char ***map);
void	ft_lst_trim(t_list **map);
void	check_map_valid(t_list *map);
void	check_surrounded_wall(char **map, size_t col, size_t row);

/*parse_map utils*/
int		is_emptyline(char *str);
int		is_palyer_pos(char c);
int		is_not_element(char *str, int *player_flag);

/*init data*/
void	init_player_info(char **map, t_player *player);
void	init_mlx_data(t_mlxdata *mlxdata, char *program_name);
void	info_to_img(t_ptr *ptr, t_map_info *info, t_img *img);

#endif