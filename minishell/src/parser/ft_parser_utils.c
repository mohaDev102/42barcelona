/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:36:55 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/08 10:36:12 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_count_lexer(t_lexer *lexer)
{
	t_lexer	*aux;
	int		i;
	int		j;

	aux = lexer;
	i = 0;
	j = 1;
	while (aux != NULL)
	{
		if (aux->type != PIPE)
			j++;
		aux = aux->next;
	}
	return (i + j);
}

t_cmd	*init_parser(void)
{
	t_cmd	*command;

	command = malloc(sizeof(t_cmd));
	if (!command)
		return (NULL);
	command->args = NULL;
	command->next = NULL;
	command->redir = NULL;
	return (command);
}

t_cmd	*add_last_cmd(t_cmd *cmd)
{
	t_cmd	*last;

	if (!cmd)
		return (0);
	last = cmd;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_add_cmd_back(t_cmd **command, t_cmd *new)
{
	t_cmd	*aux;

	if (*command != NULL)
	{
		aux = add_last_cmd(*command);
		aux->next = new;
	}
	else
		*command = new;
}

int	create_cmd(t_lexer **lexer, t_cmd **cmd, int i)
{
	t_redir	*redir;

	redir = NULL;
	if (i > 0)
	{
		(*cmd)->args = malloc(sizeof(char *) * (i + 1));
		if (!(*cmd)->args)
			return (-1);
		(*cmd)->args[i] = NULL;
	}
	if (add_cmd(lexer, cmd, &redir) == -1)
		return (-1);
	return (0);
}
