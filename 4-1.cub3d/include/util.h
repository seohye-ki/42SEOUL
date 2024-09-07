/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:51:05 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 21:20:18 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "libft.h"
# include "type.h"

void	*ft_malloc_err(size_t size);
char	*ft_strdup_err(const char *s1);
int		ft_atoi_err(const char *nptr);
void	error_exit(char *msg);
void	free_arr(char **arr);

/* mlx utils */
int		win_close(t_ptr *ptr);
int		press_handler(int key, t_mlxdata *data);
int		release_handler(int key, t_mlxdata *data);
int		render_screen(t_mlxdata *data);
void	put_image(t_ptr *ptr, void *img, int h, int w);

#endif