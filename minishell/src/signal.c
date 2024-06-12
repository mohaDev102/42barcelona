/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:45:40 by alounici          #+#    #+#             */
/*   Updated: 2024/06/11 15:20:52 by alounici         ###   ########.fr       */
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
	write(1 ,"ici", 3);
	 if (num == SIGINT)
	{
		exit_status(130);
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	 }
	// else if (sig == SIGQUIT)
	// {
	// 	// write(1, "\n", 1);
	// 	write(1, "Quit: 3", 7);
	// }
}

void	receive_signal(int status)
{
	if (status == 1)
		signal(SIGINT, parent_handler);
	else
		signal(SIGINT, child_hand);
	signal(SIGQUIT, parent_handler);
	// return (1);
}