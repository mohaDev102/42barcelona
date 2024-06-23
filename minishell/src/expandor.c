/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:37 by alounici          #+#    #+#             */
/*   Updated: 2024/06/23 18:58:31 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


char	*handle_quote(char *str, int i)
{
	char c;
	char *res;

	c = str[i];
	if (!str)
		return (str);
	res = clean_str(str, c, check_quote_number(str, c, i));
	return (res);
}

char **manage_first_dollar(char *str, t_list **envlist)
{
	char **res;
	char *aux;

	res = assembl_var(str);
	if (res == NULL)
	{
		free(str);
		return (NULL);
	}
	aux = my_getenv(*envlist, res[0], 3, 1);
	if (aux != NULL)
		res[0] = ft_strdup(aux);
	if (!res)
	{
		free_split(res);
		free(aux);
		return (NULL);
	}
	return (res);
}

char *handle_dollar(char *str, int i, t_list **envlist, int quote)
{
	char	*var_content;
	char	**res;
	int		j;
	char	*aux;

	j = 1;
	if (!str || ft_strlen(str) == 1)
		return (NULL);
	if (str[i] == '?' && (quote == 0 || quote == 2))
	{
		free(str);
		var_content = last_exit();
		return (var_content);
	}
	else if (quote == 1 || quote == 2 || quote == 0)
	{
		res = manage_first_dollar(str, envlist);
		if (!res[0] || !res)
			return (NULL);
		var_content = res[0];
		// exit(1);
		if (res[1])
		{
			while (res[j])
			{
				aux = my_getenv(*envlist, res[j], 3, 1);
				if (aux != NULL)
					var_content = ft_strjoin(var_content, aux);
				else
					var_content = ft_strjoin(var_content, res[j]);
				j++;
			}
		}
		if (quote == 2)
			free_split(res);
		else
			free(res);
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
			str[j] = handle_quote(str[j], i);
			cleaned = 1;
		}
		else if (str[j][i] == '\"')
		{
			str[j] = handle_quote(str[j], i);
			cleaned = 2;
		}
	return (cleaned);
}
int	check_quote(char *str)
{
	int i;

	while(str[i])
	{
		if (str[i] == '\'')
			return (1);
		if (str[i] == '\"')
			return (2);
		i++;
	}
	return (0);
}

int var_in_quote(char *str, int quote)
{
	int i;
	int in_quote;

	in_quote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == quote)
			in_quote = 1;
		if (str[i] == '$' && in_quote == 0)
			return(1);
		i++;
	}
	return (0);
}

char *dollar(char *str, int i, t_list **envlist, int quote)
{
	int even;

	(void)quote;
	even = check_quote_number_dollar(str);
	if (even == 0)
		return (NULL);
	str = handle_dollar(str, i + 1, envlist, quote);
	if (!str)
		return (NULL);
	return (str);
}

char *quote(char **str, int j, int i, t_list **envlist)
{
	int cleaned;

	cleaned = 0;
	if (str[j][i] == '\"' && (ft_strchr(str[j], '$') != NULL))
	{
		str[j] = dollar(str[j], i, envlist, 2);
		return (str[j]);
	}
	else
	{
		cleaned = quote_found(str, j, i);
		if (cleaned == 0 || str[j] == NULL || !str[j][i])
			return (NULL);
		return (str[j]);
		
	}
	return (NULL);
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
			str[j] = quote(str, j, i, envlist);
			return (str[j]);
		}
		else if (str[j][i] == '$')
		{
			str[j] = dollar(str[j], i, envlist, cleaned);
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

    while (cmd)
    {
		i = 0;
        while (cmd->args && cmd->args[i])
        {
			expanded = expand(cmd->args, i++, envlist);
            if (!expanded)
				cmd->args[i] = expanded;
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

//dfkhfjd$
//echo $