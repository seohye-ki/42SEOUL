/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:14:33 by seohyeki          #+#    #+#             */
/*   Updated: 2024/03/06 14:45:17 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_signum;

static void	send_signal(pid_t pid, char c)
{
	int	n;

	n = 0;
	while (n < 8)
	{
		if ((c & (1 << n)) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		n++;
		while (g_signum == 0)
			;
		g_signum = 0;
	}
}

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		exit(0);
	if (sig == SIGUSR2)
		g_signum = 1;
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	size_t	i;

	i = 0;
	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (1);
	if (signal(SIGUSR1, &handler) == SIG_ERR)
		return (1);
	if (signal(SIGUSR2, &handler) == SIG_ERR)
		return (1);
	while (argv[2][i])
	{
		send_signal(server_pid, argv[2][i]);
		i++;
	}
	send_signal(server_pid, '\0');
	return (0);
}
