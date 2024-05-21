/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:58:31 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/21 12:00:28 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_lexer	*lexer_lstlast(t_lexer *list)
{
	t_lexer	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_lexer_addback(t_lexer **lexer, t_lexer *new)
{
	t_lexer	*lst;

	if (*lexer != NULL)
	{
		lst = lexer_lstlast(*lexer);
		lst->next = new;
	}
	else
	{
		*lexer = new;
	}
}

int	ft_convert(char *str, t_lexer *new, int i)
{
	int	temp;

	if (is_signal(str[i]))
		i += ft_token(new, str, i);
	else
	{
		temp = init_word(str, i, new);
		if (temp == -1)
			return (-1);
		i += temp;
	}
	return (i);
}

void	reset_quotes(char c, int *quoted, int *quoted2)
{
	if (c == 39)
		*quoted = 0;
	else if (c == 34)
		*quoted2 = 0;
}

void	change_quotes(char c, int *quoted, int *quoted2)
{
	if (c == 39)
		*quoted = 1;
	else if (c == 34)
		*quoted2 = 1;
}
