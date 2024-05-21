/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:37:57 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/21 14:26:13 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_operation(t_lexer **lexer, t_cmd **cmd, char *env[])
{
	char	*line;

	(void)env;
	line = readline("minishell$ ");
	if (line == NULL)
	{
		printf("exit\n");
		return (1);
	}
	if (ft_lexer(line, lexer) == 0)
	{
		if (ft_parse(cmd, *lexer) != -1)
		{
			her_doc(*cmd, env);
			// if (!expandor())
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