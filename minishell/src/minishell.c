/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:37:57 by mel-atta          #+#    #+#             */
/*   Updated: 2024/07/21 13:27:42 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	set_null(t_lexer **lexer, t_cmd **cmd, char **my_env)
{
	(void)cmd;
	(void)my_env;
	(void)lexer;
	lexer = NULL;
	cmd = NULL;
	my_env = NULL;
}

int	ft_operation(t_lexer **lexer, t_cmd **cmd, char *env[], t_list **envlist)
{
	char	*line;
	char	**my_env;

	line = readline("minishell$ ");
	if (line == NULL)
	{
		printf("exit\n");
		return (1);
	}
	my_env = copy_env(env);
	if (ft_lexer(line, lexer) == 0)
	{
		if (ft_parse(cmd, *lexer) != -1)
		{
			her_doc(*cmd);
			if (!expandor(*cmd, envlist))
				executor(cmd, envlist, my_env);
		}
	}
	lexer_clear(cmd, lexer);
	free_env(my_env);
	set_null(lexer, cmd, my_env);
	free(line);
	return (0);
}

int	main(int argc, char *argv[], char *env[])
{
	t_lexer	*lexer;
	t_cmd	*cmd;
	t_list	*envlist;

	lexer = NULL;
	cmd = NULL;
	envlist = NULL;
	rl_catch_signals = 0;
	(void)argv;
	if (argc > 1)
		printf("Error\n");
	envlist = ft_list(env);
	receive_signal(1, 0);
	while (1)
	{
		if (ft_operation(&lexer, &cmd, env, &envlist))
			break ;
	}
	free_envlist(envlist);
	return (exit_status(0));
}
