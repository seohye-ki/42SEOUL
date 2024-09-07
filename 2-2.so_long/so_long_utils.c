/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:37:27 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 20:11:08 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_file(char *file_name)
{
	if (ft_strrchr(file_name, '.') != NULL)
	{
		if (ft_strncmp(ft_strrchr(file_name, '.'), ".ber\0", 5) == 0)
			return (1);
	}
	return (0);
}

void	print_error(void)
{
	ft_printf("error\n");
	exit(1);
}

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
