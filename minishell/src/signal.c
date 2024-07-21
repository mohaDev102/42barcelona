/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:45:40 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 11:42:10 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include "../inc/minishell.h"

void	hd_hand(int num)
{
	struct termios	term;

	if (isatty(STDIN_FILENO))
	{
		if (tcgetattr(STDIN_FILENO, &term) != -1)
		{
			term.c_lflag |= ECHO;
			tcsetattr(STDIN_FILENO, TCSANOW, &term);
		}
	}
	(void)num;
	exit(1);
}

void	parent_handler(int num)
{
	if (num == SIGINT)
	{
		exit_status(130);
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	child_hand(int num)
{
	(void)num;
	exit_status(130);
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
}

int	receive_signal(int status, int fd)
{
	if (status == 1)
	{
		signal(SIGINT, parent_handler);
		signal(SIGQUIT, parent_handler);
	}
	else if (status == 2)
	{
		signal(SIGINT, child_hand);
		signal(SIGQUIT, parent_handler);
		return (0);
	}
	else if (status == 3)
	{
		signal(SIGINT, hd_hand);
		close(fd);
	}
	signal(SIGQUIT, parent_handler);
	return (1);
}
