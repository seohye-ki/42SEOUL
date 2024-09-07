/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:22:18 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/17 12:22:36 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				fd;
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	size_t	pos;
	size_t	len;
	ssize_t	read_size;
	char	*buf;
	char	*line;
}	t_data;

int		ft_find_nl(const char *s, t_data *data);
void	ft_strcat(char *dest, const char *src);
char	*ft_re_malloc(char *origin, size_t size);
int		add_newnode(t_list **previous, t_list **fdlst, int fd);
char	*get_next_line(int fd);

#endif