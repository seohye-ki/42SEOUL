/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:55:01 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/31 01:53:28 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <termios.h>
#include <signal.h>

static void	set_terminal_print_off(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

static void	set_terminal_print_on(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= (ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	set_sig_term(void sigint(int), void sigquit(int), int term)
{
	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
	if (term == 1)
		set_terminal_print_on();
	else if (term == 0)
		set_terminal_print_off();
}

void	set_terminal_echo_on(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= (ECHO);
	tcsetattr(1, 0, &term);
}
