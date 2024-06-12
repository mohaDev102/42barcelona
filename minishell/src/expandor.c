/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:37 by alounici          #+#    #+#             */
/*   Updated: 2024/06/10 16:41:56 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


char	*handle_quote(char *str, int i)
{
	char c;
	char *res;

	// printf("%s", str);
	c = str[i];
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
	char *temp;
	char *aux;

	j = 0;
	if (!check_quote_number(str, '\"'))
		return (NULL);
	if (!str[i] || ft_strlen(str) == 1)
		return (str);
	// printf("%c", str[i]);
	if (str[i] == '?' && quote != 1)
	{
			var_content = last_exit();
			return (var_content);
	}
	else if (quote != 1)
	{
		res = join_var_name(str, 0);
		aux = my_getenv(*envlist, res[j], 3);
		if (aux != NULL)
			var_content = ft_strdup(aux);
		else
			var_content = ft_strdup(res[j]);
		if (!var_content)
		{
			free_split(res);
			return (NULL);
		}
		if (res[1])
		{
			j++;
			while (res[j])
			{
				temp = var_content;
				aux = my_getenv(*envlist, res[j], 3);
				if (aux != NULL)
					var_content = ft_strjoin(var_content, aux);
				else
					var_content = ft_strjoin(var_content, res[j]);
				free(temp);
				j++;
			}
			   i = 0;
		}
		free_split(res);
	}
	else
		return (str);
	return (var_content);
}

int dollar_found(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return(1);
		i++;
	}
	return (0);
}

int	quote_found(char **str, int j, int i)
{
	int cleaned;

	cleaned = 0;

		if (str[j][i] == '\'')
		{
			char *new_str = handle_quote(str[j], i);
			if (!new_str)
				return (0);
			free(str[j]);
			str[j] = new_str;
			cleaned = 1;
		}
		else if (str[j][i] == '\"')
		{
			char *new_str = handle_quote(str[j], i);
			if (!new_str)
				return (0);
			free(str[j]);
			str[j] = new_str;
			cleaned = 2;
		}
	return (cleaned);
}

char *expand(char **str, int j, t_list **envlist)
{
    int	i;
	int cleaned;
	char *expanded;

	cleaned = 0;
	i = 0;
	if (!str[j])
		return (NULL);
	while (str[j][i])
	{
		if ((str[j][i] == '\'' || str[j][i] == '\"') && cleaned == 0)
		{
			if (str[j][i] == '\"' && (ft_strchr(str[j], '$') != NULL))
			{
				expanded = handle_dollar(str[j], i + 1, envlist, 2);
				if (!expanded)
					return (NULL);
				free(str[j]);
				str[j] = expanded;
				return (str[j]);
			}
			else
			{
				cleaned = quote_found(str, j, i);
				if (cleaned == 0 || str[j] == NULL || !str[j][i])  
					return (NULL);
			}
			i++;
		}
		else if (str[j][i] == '$')
		{
			expanded = handle_dollar(str[j], i + 1, envlist, cleaned);
			if (!expanded)
			{
				return (NULL);
			}
			free(str[j]);
			str[j] = expanded;
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
			// printf(" expa%s\n", cmd->args[i]);
            if (!expanded)
			{
				// free(cmd->args[i]);
				cmd->args[i] = expanded;
			}
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
