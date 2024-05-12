/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:37:46 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/05 12:37:47 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_token(t_lexer *lexer, char *str)
{
	int	i;

	i = 0;
	if (str[i] == PIPE_AS)
		lexer->type = PIPE;
	else if (str[i] == GREAT_AS && str[i + 1] == GREAT_AS)
		lexer->type = GREAT_L;
	else if (str[i] == LESS_AS && str[i + 1] == LESS_AS)
		lexer->type = LESS_L;
	else if (str[i] == LESS_AS)
		lexer->type = LESS;
	else if (str[i] == GREAT_AS)
		lexer->type = GREAT;
	if (lexer->type == LESS_L || lexer->type == GREAT_L)
		i = 2;
	else
		i = 1;
	return (i);
}

int	init_word(char *str, int i, t_lexer *new)
{
	int		quoted;
	int		quoted2;
	char	*word;
	int		j;

	quoted = 0;
	quoted2 = 0;
	j = 0;
	while (str[i + j] != '\0')
	{
		if (ft_isquote(str[i + j]) == 1 && (quoted == 1 || quoted2 == 1))
			reset_quotes(str[i + j], &quoted, &quoted2);
		else if (ft_isquote(str[i + j]) == 1 && (quoted == 0 || quoted2 == 0))
			change_quotes(str[i + j], &quoted, &quoted2);
		if ((ft_isspace(str[i + j]) == 1 || is_signal(str[i + j]) == 1)
			&& (quoted2 == 0 && quoted == 0))
			break ;
		j++;
	}
	word = ft_substr(str, i, j);
	if (!word)
		return (-1);
	new->value = word;
	return (j);
}

int	ft_space_or_null(char *str, int i)
{
	while (str[i] == 32)
		i++;
	if (str[i] == '\0')
		return (-1);
	add_history(str);
	return (0);
}

int	ft_lexer(char *line, t_lexer **lexer)
{
	size_t	i;
	t_lexer	*new;
	int		checker;

	i = 0;
	if (ft_space_or_null(line, i) == -1)
		return (1);
	while (i < ft_strlen(line))
	{
		if (ft_isspace(line[i]))
			i++;
		else
		{
			new = init_lexer();
			if (!new)
				return (1);
			ft_lexer_addback(lexer, new);
			checker = ft_convert(ft_substr(line, i, ft_strlen(line)), new);
			if (!checker)
				return (1);
			i += checker;
			i++;
		}
	}
	return (0);
}
