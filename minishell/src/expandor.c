/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:37 by alounici          #+#    #+#             */
/*   Updated: 2024/05/31 20:46:32 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


char	*handle_quote(char *str, int i, int flag)
{
	int j = 0;
	int singleq;
	int doubleq;
	char c;
	char *res;

	singleq = 0;
	doubleq = 0;
	j = i;
	c = str[i];
	flag = j;
	res = NULL;
	i++;
	if (!str)
		return (str);
	while (str[i])
	{
		if (str[i] == c)
		{
			if (i == 1)
				return (NULL);
			if (flag == 1)
				singleq = 1;
			if (flag == 2)
				doubleq = 1;
			res = clean_str(str, j, i);
			return (res);
		}
		i++;
	}
	if (singleq == 0 && doubleq == 0)
		return(NULL);
	return (res);
}

char *handle_dollar(char *str, int i, t_list **envlist, int quote)
{
	char *varname;
	char *res;
	// write(2, "22", 2);
	if (str[i] == '?' && quote != 1)
	{
		res = last_exit();
	}
	else if (ft_strlen(str) == 1)
	{
		return (str);
	}
	else if (quote != 1)
	{
		varname = extract_var_name(str, i);
		res = my_getenv(*envlist, varname, 0);
		if (res == NULL)
			return (NULL);
	}
	else
		return (str);
	return (res);
}

int	quote_found(char **str, int j, int i)
{
	int cleaned;

	cleaned = 0;
		if (str[j][i] == '\'')
		{
			str[j] = handle_quote(str[j], i, 1);
			if (!str[j])
				return (0);
			cleaned = 1;
		}
		else if (str[j][i] == '\"')
		{
			str[j] = handle_quote(str[j], i, 2);
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
				if (cleaned == 0 || str[j] == NULL)  
					return (NULL);
				if (!str[j][i])
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
				return (1);
			tmp = tmp->next;
		}
		
        cmd = cmd->next;
    }
	return (0);
}