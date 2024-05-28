/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:36:41 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/28 11:38:40 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_lexer	*ft_last_lexer(t_lexer **lexer)
{
	t_lexer	*aux;

	aux = *lexer;
	while (aux != NULL && aux->next != NULL)
	{
		aux = aux->next;
	}
	return (aux);
}

int	check_pipes(t_lexer **lexer)
{
	if ((*lexer)->type == 1 || ft_last_lexer(lexer)->type == 1)
		return (1);
	return (0);
}

void	ft_error(t_lexer **lexer)
{
	if ((*lexer)->type == 1 || ft_last_lexer(lexer)->type == 1)
		write(2, "bash: syntax error near unexpected token |\n", 44);
	else if (ft_last_lexer(lexer)->type == 2 || ft_last_lexer(lexer)->type == 3
		|| ft_last_lexer(lexer)->type == 4 || ft_last_lexer(lexer)->type == 5)
		write(2, "bash: syntax error near unexpected token 'newline'\n", 52);
}

int ft_count_args(t_lexer *aux)
{
	//redir OJO
	int i;

	i = 0;
	while (aux && aux->type != PIPE)
	{
		if (aux->type == NOTH)
			i++;
		if (aux->type != NOTH && aux->next != NULL)
			aux = aux->next;
		aux = aux->next;
	}
	return (i);
}

int	ft_parse(t_cmd **commands, t_lexer *lexer)
{
	t_lexer	*aux;
	t_cmd	*new;
	int		count_args;

	aux = lexer;
	if (check_pipes(&lexer) || ft_last_lexer(&lexer)->type == 1
		|| ft_last_lexer(&lexer)->type == 1 || ft_last_lexer(&lexer)->type == 2
		|| ft_last_lexer(&lexer)->type == 3 || ft_last_lexer(&lexer)->type == 4
		|| ft_last_lexer(&lexer)->type == 5 || check_error(aux))
	{
		return (ft_error(&lexer), -1);
	}
	while (aux != NULL)
	{
		count_args = ft_count_args(aux);
		new = init_parser();
		if (!new)
			return (1);
		ft_add_cmd_back(commands, new);
		if (create_cmd(&aux, &new, count_args) == -1)
			return (-1);
		if (aux != NULL)
			aux = aux->next;
	}
	return (0);
}
