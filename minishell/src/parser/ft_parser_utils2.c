/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:37:06 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/05 12:51:53 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_redir	*init_redir(void)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->file = NULL;
	redir->type = 0;
	redir->next = NULL;
	return (redir);
}

void	free_cmd_list(t_cmd *cmd)
{
	t_cmd	*temp;
	int		i;

	while (cmd != NULL)
	{
		if (cmd->args != NULL)
		{
			i = 0;
			while (cmd->args[i] != NULL)
			{
				free(cmd->args[i]);
				i++;
			}
			free(cmd->args);
			cmd->args = NULL;
		}
		// Liberar la memoria asignada para redir, si es necesario
		// Aquí puedes agregar la lógica para liberar la estructura
		// t_redir si es necesario
		// Mover al siguiente nodo de la lista y liberar el nodo actual
		temp = cmd;
		cmd = cmd->next;
		free(temp);
	}
}

int	is_redirect(t_lexer **lexer, t_redir **redir)
{
	t_redir	*new;

	new = init_redir();
	if (!new)
		return (-1);
	if ((*lexer)->type == GREAT)
		new->type = OUTFILE;
	else if ((*lexer)->type == GREAT_AS)
		new->type = APPEND;
	else if ((*lexer)->type == LESS)
		new->type = INFILE;
	else if ((*lexer)->type == LESS_L)
		new->type = HERDOC;
	new->file = ft_strdup((*lexer)->next->value);
	if (!new->file)
		return (-1);
	ft_parser_addback(redir, new);
	(*lexer) = (*lexer)->next;
	return (0);
}

int	add_cmd(t_lexer **lexer, t_cmd **cmd, t_redir **redir)
{
	int	i;

	i = 0;
	while ((*lexer) && (*lexer)->type != PIPE)
	{
		if ((*lexer)->type != NOTH)
		{
			if (is_redirect(lexer, redir) == -1)
				return (-1);
		}
		else
		{
			(*cmd)->args[i] = ft_strdup((*lexer)->value);
			if (!(*cmd)->args[i])
				return (ft_free((*cmd)->args, i), -1);
			i++;
		}
		(*lexer) = (*lexer)->next;
	}
	(*cmd)->redir = *redir;
	return (0);
}
// quitarlo
void	ft_print_parser(t_cmd **cmd)
{
	t_cmd	*aux;
	int		i;

	i = 0;
	aux = *cmd;
	while (aux != NULL)
	{
		printf("valores: %s\n", aux->args[i++]);
		aux = aux->next;
	}
}
// quitarlo
void	ft_print_redir(t_redir **redir)
{
	t_redir	*aux;

	aux = *redir;
	while (aux != NULL)
	{
		aux = aux->next;
	}
}
