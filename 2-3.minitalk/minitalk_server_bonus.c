/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:49:53 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/06 14:46:04 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sigdata	g_data;

static void	get_signal(int sig)
{
	if (sig == 2)
		g_data.c += (1 << g_data.count);
	(g_data.count)++;
	if (g_data.count == 8)
	{
		write(1, &g_data.c, 1);
		if (g_data.c == '\0')
		{
			if (kill(g_data.client_pid, SIGUSR1) == -1)
				exit(1);
			g_data.count = 0;
			g_data.c = 0;
			g_data.signum = 0;
			return ;
		}
		g_data.count = 0;
		g_data.c = 0;
	}
	g_data.signum = 0;
	if (kill(g_data.client_pid, SIGUSR2) == -1)
		exit(1);
}

static void	handler(int sig, siginfo_t *info, void *s)
{
	(void)s;
	g_data.client_pid = info->si_pid;
	if (sig == SIGUSR1)
		g_data.signum = 1;
	else if (sig == SIGUSR2)
		g_data.signum = 2;
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
		return (1);
	ft_printf("server_pid: %d\n", getpid());
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		return (1);
	while (1)
	{
		if (g_data.signum == 1)
			get_signal(1);
		else if (g_data.signum == 2)
			get_signal(2);
	}
	return (0);
}
