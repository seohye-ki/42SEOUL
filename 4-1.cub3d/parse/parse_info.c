/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:47:36 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/06 15:41:48 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

static int	find_n_save(char **split, t_map_info *info, int *cnt)
{
	if (!info->north && ft_memcmp("NO", split[0], 3) == 0 && !split[2])
		info->north = ft_strdup_err(split[1]);
	else if (!info->south && ft_memcmp("SO", split[0], 3) == 0 && !split[2])
		info->south = ft_strdup_err(split[1]);
	else if (!info->west && ft_memcmp("WE", split[0], 3) == 0 && !split[2])
		info->west = ft_strdup_err(split[1]);
	else if (!info->east && ft_memcmp("EA", split[0], 3) == 0 && !split[2])
		info->east = ft_strdup_err(split[1]);
	else if (!info->floor && ft_memcmp("F", split[0], 2) == 0 && !split[2])
		info->floor = ft_strdup_err(split[1]);
	else if (!info->ceiling && ft_memcmp("C", split[0], 2) == 0 && !split[2])
		info->ceiling = ft_strdup_err(split[1]);
	else
	{
		free_arr(split);
		return (1);
	}
	(*cnt)++;
	free_arr(split);
	return (0);
}

void	parse_map_info(int fd, t_map_info *info)
{
	char	*buff;
	char	**split;
	int		cnt;

	cnt = 0;
	while (cnt < 6)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		buff[ft_strlen(buff) - 1] = '\0';
		if (is_emptyline(buff))
		{
			free(buff);
			continue ;
		}
		split = ft_split(buff, ' ');
		if (split == NULL)
			error_exit("Malloc failed.");
		free(buff);
		if (split[0] && find_n_save(split, info, &cnt) > 0)
			break ;
	}
	if (cnt != 6)
		error_exit("Wrong graphic information.");
}
