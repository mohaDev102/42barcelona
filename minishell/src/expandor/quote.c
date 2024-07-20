/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:37:30 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 17:18:56 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	quote_found(char **str, int j, int i)
{
	int cleaned;

		if (str[j][i] == '\'')
		{
			handle_quote(str, j);
			cleaned = 1;
		}
		else if (str[j][i] == '\"')
		{
			handle_quote(str, j);
			cleaned = 2;
		}
	return (cleaned);
}

char *quote(char **str, int j, int i, t_list **envlist)
{
	int cleaned;
	char *tmp;

	cleaned = 0;
	if (ft_strchr(str[j], '$') != NULL && var_in_quote(str[j], '\'') == 0)
	{
		tmp = str[j];
		str[j] = dollar(tmp, i, envlist);
		if (str[j] == NULL)
			return (ft_strdup(""));
		handle_quote(str, j);
		free(tmp);
		return (str[j]);
	}
	else
	{
		cleaned = quote_found(str, j, i);
		if (cleaned == 0 || str[j] == NULL)
			return (NULL);
		return (str[j]);
		
	}
	return (NULL);
}

int var_in_quote(char *str, char quote)
{
	int i;
	int in_quote;

	quote = '\'';
	in_quote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == quote && in_quote == 0)
			in_quote = 1;
		else if (str[i] == quote && in_quote == 1)
			in_quote = 0;
		if (str[i] == '$' && in_quote == 1)
			return(1);
		i++;
	}
	return (0);
}

int quote_clean2(int flag, int *next, int l)
{
	flag++;
	*next = l;
	return (flag);
}

int quote_clean(char **str, int j, char *substr, int i)
{
	int l;
	int k;
	int next;
	char c;
	int flag;
	
	c = str[j][i];
	value_set(&flag, &l, &k);
	if (ft_strlen(str[j]) == (unsigned int)i)
		return (0);
	while (l < i)
		substr[k++] = str[j][l++];
	l++;
	while (str[j][l]) 
	{
		if (str[j][l] == c && (flag == 0))
			flag = quote_clean2(flag, &next, l);
		else if (str[j][l] != c || (str[j][l] == c && flag == 1))
			substr[k++] = str[j][l];
		l++;
	}
	substr[k] = '\0';
	free_update(str, j, substr);
	return (next);
}
