/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:37:57 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/21 17:17:16 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_operation(t_lexer **lexer, t_cmd **cmd, char *env[])
{
	char	*line;
	// int		val;
	t_list	*envlist;

	(void)env;
	line = readline("minishell$ ");
	if (line == NULL)
	{
		printf("exit\n");
		return (1);
	}
	envlist = ft_list(env);
	if (ft_lexer(line, lexer) == 0)
	{
		if (ft_parse(cmd, *lexer) != -1)
		{
			her_doc(*cmd, env);
			// if (!expandor())
			// write(1, "ici", 3);
			if (!expandor(*cmd, &envlist))
			{
				// printf("iciii%s\n", (*cmd)->args[0]);
				executor(cmd, lexer, env);
			}
			executor(cmd, env);
		}
	}
	lexer_clear(cmd, lexer);
	// parser_free(cmd);
	// lexer_clear(lexer);
	lexer = NULL;
	cmd = NULL;
	free(line);
	return (0);
}

int	main(int argc, char *argv[], char *env[])
{
	t_lexer *lexer;
	t_cmd *cmd;

	lexer = NULL;
	cmd = NULL;
	rl_catch_signals = 0;
	(void)argv;
	if (argc > 1)
	{
		printf("Error\n");
	}
	receive_signal(1);
	while (1)
	{
		if (ft_operation(&lexer, &cmd, env))
			break ;
	}
	return (g_error);
}