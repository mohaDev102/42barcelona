/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:45:40 by alounici          #+#    #+#             */
/*   Updated: 2024/04/27 17:45:43 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
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
// 				write(1, "ici1", 4);
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


void	signal_hand_default(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_hand(int signum)
{
	write(1 ,"ici", 3);
	if (signum == SIGINT)
		write(1, "\n", 1);
}

void	receive_signal(int status)
{
	if (status == 1)
		signal(SIGINT, signal_hand_default);
	else
		signal(SIGINT, signal_hand);
	signal(SIGQUIT, signal_hand_default);
	// return (1);
}