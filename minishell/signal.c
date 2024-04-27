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
#include "minishell.h"

int	g_return_value = 0;

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_return_value = 1;
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_return_value = 0;
	}
}

void	handler_child(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_return_value = 130;
	}
	else if (sig == SIGQUIT)
	{
		write(1, "Quit: 3", 7);
		g_return_value = 131;
	}
}

void	receive_signal(int id)
{
	if (id == 0)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
	}
	else
	{
		signal(SIGINT, handler_child);
		signal(SIGQUIT, handler_child);
	}
}
