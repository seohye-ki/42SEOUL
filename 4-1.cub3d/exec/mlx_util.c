/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:30:33 by seohyeki          #+#    #+#             */
/*   Updated: 2024/05/03 11:35:44 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "mlx.h"

int	win_close(t_ptr *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	exit(EXIT_SUCCESS);
}

void	put_image(t_ptr *ptr, void *img, int h, int w)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, \
							img, w, h);
}
