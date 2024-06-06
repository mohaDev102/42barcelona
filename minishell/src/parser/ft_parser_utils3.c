/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:52:50 by mel-atta          #+#    #+#             */
/*   Updated: 2024/06/02 12:15:23 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_parser_addback(t_redir **redir, t_redir *new)
{
	t_redir	*lst;

	if (*redir != NULL)
	{
		lst = redir_lstlast(*redir);
		lst->next = new;
	}
	else
	{
		*redir = new;
	}
}

t_redir	*redir_lstlast(t_redir *redir)
{
	t_redir	*aux;

	if (!redir)
		return (0);
	aux = redir;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	return (aux);
}

int	check_error(t_lexer *lexer)
{
	while (lexer->next != NULL)
	{
		if ((lexer->type == GREAT && lexer->next->type == PIPE) || \
			(lexer->type == LESS && lexer->next->type == PIPE) || \
			(lexer->type == LESS_L && lexer->next->type == PIPE) || \
			(lexer->type == GREAT_L && lexer->next->type == PIPE) || \
			(lexer->type == LESS && lexer->next->type == GREAT) || \
			(lexer->type == GREAT && lexer->next->type == LESS) || \
			(lexer->type == PIPE && lexer->next->type == PIPE))
		{
			write(2, "bash: syntax error near unexpected token 'newline'\n", 52);
			return (-1);
		}
		lexer = lexer->next;
	}
	return (0);
}
