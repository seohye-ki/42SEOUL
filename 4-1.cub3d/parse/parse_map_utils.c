/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:59:35 by seohyeki          #+#    #+#             */
/*   Updated: 2024/05/06 15:42:24 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

int	is_emptyline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (1);
	return (0);
}

int	is_palyer_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_not_element(char *str, int *player_flag)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == ' ')
			i++;
		else if (is_palyer_pos(str[i]))
		{
			if (*player_flag)
				error_exit("Invalid map.");
			else
				*player_flag = 1;
			i++;
		}
		else
			return (1);
	}
	return (0);
}
