/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:28:14 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/26 02:34:58 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define TYPE_DEFAULT 0
# define TYPE_HEREDOC 1
# define TYPE_INPUT 2
# define TYPE_OUTPUT_T 3
# define TYPE_OUTPUT_A 4
# define TYPE_PIPE 5
# define SYNTAX_ERROR 1

# include "libft.h"

typedef struct s_token
{
	char	*str;
	int		type;
	int		hd_index;
	int		redirect_flag;
}				t_token;

typedef struct s_parsedata
{
	char	*str;
	char	*env_str;
	t_list	*token_head;
}				t_parsedata;

char	*get_env_name(char *str);
void	count_total_len(char *str, t_list *env, size_t *len);
void	change_default(t_parsedata *data, size_t *i, size_t *j, t_list *env);
void	change_quote(t_parsedata *data, size_t *i, size_t *j, t_list *env);
void	parsing_env(t_parsedata *data, t_list *env);
int		split_token(t_list **head, char *str);
int		check_token_type(char *str);
void	delete_quote(t_list **head);
int		beautify_token(t_list **head, t_list **pipe);
int		parsing(t_parsedata *parse, t_list **pipe, t_list *env);

/*parse utils*/
int		ft_ispipe(char c);
int		ft_isredi(char c);
int		ft_isquote(char c);
char	*ft_strndup(char *origin, int count);

#endif