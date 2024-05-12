/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:52:50 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/06 11:12:44 by mel-atta         ###   ########.fr       */
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
