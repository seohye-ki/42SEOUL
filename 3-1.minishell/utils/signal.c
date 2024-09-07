/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:34:57 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/29 17:54:08 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>

volatile sig_atomic_t	g_sig;

void	sig_update(t_list *env)
{
	if (g_sig == -1)
	{
		g_sig = 0;
		update_env("?", "1", env);
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGINT)
		g_sig = signum;
}

int	ctrl_c_new_prompt(void)
{
	if (g_sig == SIGINT)
	{
		g_sig = -1;
		write(1, "\n", 1);
		if (rl_on_new_line() < 0)
			error_exit("readline error", 0, 0, EXIT_FAILURE);
		rl_replace_line("", 1);
		rl_redisplay();
	}
	return (0);
}

int	ctrl_c_heredoc(void)
{
	if (g_sig == SIGINT)
	{
		g_sig = 0;
		write(1, "\n\033[1B\033[1A", 1);
		if (rl_on_new_line() < 0)
			error_exit("readline error", 0, 0, EXIT_FAILURE);
		rl_replace_line("", 1);
		exit(100);
	}
	return (0);
}
