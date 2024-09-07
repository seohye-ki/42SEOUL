/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:32:44 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/29 17:55:21 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "libft.h"

/*prompt*/
char	*prompt_shell(t_list *env);
char	*prompt_heredoc(void);

/*signal*/
void	sig_update(t_list *env);
void	sig_handler(int signum);
int		ctrl_c_new_prompt(void);
int		ctrl_c_heredoc(void);
void	set_sig_term(void sigint(int), void sigquit(int), int term);
void	set_terminal_echo_on(void);

/*free*/
void	free_token(void *token);
void	free_tokens_in_pipe(void *node);
void	free_arr(char **arr);

/*error*/
void	error_exit(char *msg, char *cmd, char *arg, int code);
void	error_msg_only(char *msg, char *cmd, char *arg);

/*utils*/
void	*ft_malloc_err(size_t size);
char	*ft_strjoin_sep(char const *s1, char const *s2, char const *sep);
char	*ft_strdup_err(const char *s1);
int		ft_isspace(char c);
int		find_env_name(char *content, char *name, int only_with_eq_flag);
t_list	*envp_to_lst(char **envp);
char	*find_env(char *name, t_list *env);
void	no_value_update_env(char *name, t_list *env);
void	update_env(char *name, char *value, t_list *env);

#endif