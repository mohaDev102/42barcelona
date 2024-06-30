/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:45:40 by alounici          #+#    #+#             */
/*   Updated: 2024/06/30 14:46:09 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include "../inc/minishell.h"

// void	handler(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		write(1, "\n", 1);
// 		rl_replace_line("", 0);
// 		rl_on_new_line();
// 		rl_redisplay();
// 		exit_status(1);
// 	}
// }

// void	handler_child(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		write(2, "\n", 1);
// 			rl_on_new_line();
// 		rl_replace_line("", 0);
// 		// rl_on_new_line();
// 		rl_redisplay();
// 	// 	// exit_status(130);
// 	}
// 	// if (sig == SIGQUIT)
// 	// {
// 	// 	// write(1, "\n", 1);
// 	// 	write(1, "Quit: 3", 7);
// 	// 	// exit(131);
// 	// }
// }

// void	receive_signal(int id)
// {
// 	if (id == 1)
// 	{
// 		signal(SIGINT, handler);
// 		// signal(SIGQUIT, SIG_IGN);
// 	}
// 	else if (id == 2)
// 	{
// 		write(1, "ici", 3);
// 		signal(SIGINT, handler);
// 		// signal(SIGQUIT, handler);
// 	}
// 		signal(SIGQUIT, SIG_IGN);
// 			write(1, "ic3", 3);
// }


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
	// 			write(1, "ici1", 4);
	(void)num;
	// write(2, "\n", 1);
	// rl_replace_line("", 1);
	// return ;
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
	// write(1 ,"ici", 3);
	(void)num;
	//  if (num == SIGINT)
	// {
		exit_status(130);
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		// rl_redisplay();
	//  }
	// else if (sig == SIGQUIT)
	// {
	// 	// write(1, "\n", 1);
		// write(1, "Quit: 3", 7);
	// }
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