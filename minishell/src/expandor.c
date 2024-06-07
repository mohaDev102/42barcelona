/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:37 by alounici          #+#    #+#             */
/*   Updated: 2024/06/02 16:20:20 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


char	*handle_quote(char *str, int i)
{
	// int j = 0;
	// int singleq;
	// int doubleq;
	char c;
	char *res;
	// char *aux;
	// int k;

	// k = 0;
	// singleq = 0;
	// doubleq = 0;
	// j = i;
	c = str[i];
	// flag = j;
	if (!str)
		return (str);
	if (!check_quote_number(str, c))
		return (NULL);
	res = clean_str(str, c, check_quote_number(str, c));
	return (res);
}

char *handle_dollar(char *str, int i, t_list **envlist, int quote)
{
	char *var_content;
	char **res;
	int j;

	j = 0;
	if (!str[i])
		return (str);
	if (str[i] == '?' && quote != 1)
		return (last_exit());
	else if (ft_strlen(str) == 1)
		return (str);
	else if (quote != 1)
	{
		res = join_var_name(str, i);
		if (!res || *res)
			return (NULL);
		var_content = my_getenv(*envlist, res[j], 3);
		// printf("%s\n", var_content);
		if (ft_strlen(*res) > 1)
		{
			j++;
			while (res[j])
			{
				var_content = ft_strjoin(var_content, my_getenv(*envlist, res[j], 3));
				j++;
			}
		}
		if (res == NULL)
			return (NULL);
	}
	else
		return (str);
	return (var_content);
}

int	quote_found(char **str, int j, int i)
{
	int cleaned;

	cleaned = 0;
		if (str[j][i] == '\'')
		{
			str[j] = handle_quote(str[j], i);
			if (!str[j])
				return (0);
			cleaned = 1;
		}
		else if (str[j][i] == '\"')
		{
			str[j] = handle_quote(str[j], i);
			if (!str[j])
			{
				return (0);
			}
			cleaned = 2;
		}
	return (cleaned);
}

char *expand(char **str, int j, t_list **envlist)
{
    int	i;
	int cleaned;

	cleaned = 0;
	i = 0;
	if (!str[j])
		return (NULL);
	while (str[j][i])
	{
		if ((str[j][i] == '\'' || str[j][i] == '\"') && cleaned == 0)
		{
			cleaned = quote_found(str, j, i);
			if (cleaned == 0 || str[j] == NULL || !str[j][i])  
				return (NULL);
			if (str[j][i] == '$')
			{
				str[j] = handle_dollar(str[j], i + 1, envlist, cleaned);
				if (!str[j])
					return (NULL);
			}
		}
		else if (str[j][i] == '$')
		{
			str[j] = handle_dollar(str[j], i + 1, envlist, cleaned);
			if (!str[j])
				return (NULL);
			return (str[j]);
		}
		i++;
	}
	return (str[j]);
}

int expandor(t_cmd *cmd, t_list **envlist)
{
    int i;
	char *expanded;
	t_redir *tmp;
    i = 0;
    while (cmd)
    {
		i = 0;
        while (cmd->args && cmd->args[i])
        {
			expanded = expand(cmd->args, i, envlist);
            if (expanded)
				cmd->args[i] = expanded;
			i++;
        }
		tmp = cmd->redir;
		while (tmp)
		{
			if (expand(&(tmp->file), 0, envlist))
				return (0);
			tmp = tmp->next;
		}
        cmd = cmd->next;
    }
	return (0);
}
