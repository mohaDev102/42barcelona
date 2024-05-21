/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:37:57 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/20 20:28:13 by alounici         ###   ########.fr       */
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
		// ft_print_lexer(lexer);
		// val = execve("/bin/cat", &(*lexer)->value, NULL);
		// if (val == -1)
			// return (1);
		if (ft_parse(cmd, *lexer) != -1)
		{
			// write(1, "entra\n", 6);
			// ft_print_parser(cmd);
			// ft_print_redir(cmd);
			// her_doc(*cmd, env);
			// if (!expandor())
			// write(1, "ici", 3);
			if (!expandor(*cmd, &envlist))
			{
				// printf("iciii%s\n", (*cmd)->args[0]);
				executor(cmd, lexer, env);
			}
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
		// line = readline("minishell$ ");
		// if (line == NULL)
		// {
		// 	printf("exit\n");
		// 	return (1);
		// }
		// if (ft_lexer(line, lexer) == 0)
		// {
		
		// 	printf("no error?");
		// 	// printf("%s", (*lexer)->value);
		// 	// if (ft_parse())
		// 	// {
		// 	//     her_doc();
		// 	//     if (!expandor())
		// 	//         executor();
		// 	// }
		// }
		// if (!ft_strncmp(line, "exit", 4))
		// {
		//     write(1, "exit\n", 5);
		//     free(line);
		//     exit(0);
		// }
		// ft_lexer(line);
	}
	// free(line);
	return (g_error);
}