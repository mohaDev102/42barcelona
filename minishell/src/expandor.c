/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:37 by alounici          #+#    #+#             */
/*   Updated: 2024/06/19 19:44:53 by alounici         ###   ########.fr       */
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

char **manage_first_dollar(char *str, t_list **envlist)
{
	char **res;
	char *aux;

	res = assembl_var(str);
	aux = my_getenv(*envlist, res[0], 3);
	if (aux != NULL)
		res[0] = ft_strdup(aux);
	else
		return (NULL);
	if (!res[0])
	{
		free_split(res);
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
	if (!str[i] || ft_strlen(str) == 1)
		return (str);
	if (str[i] == '?' && (quote == 1 || quote == 2))
	{
		var_content = last_exit();
		return (var_content);
	}
	else if (quote == 1 || quote == 2)
	{
		res = manage_first_dollar(str, envlist);
		if (res == NULL)
			return (NULL);
		var_content = res[0];
		if (res[1])
		{
			while (res[j])
			{
				aux = my_getenv(*envlist, res[j], 3);
				if (aux != NULL)
					var_content = ft_strjoin(var_content, aux);
				else
					var_content = ft_strjoin(var_content, res[j]);
				j++;
			}
		}
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
int	check_quote(char *str)
{
	int i;

	// printf("quote%s", str);
// write(1, "ici", 3);
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
	// int dollar;
	int in_quote;

	// dollar = 0;
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
	char *expanded;
	int quote1;
	int even;

	(void)quote;
	quote1 = 1;
	// printf("dollar%s", str);
	// quote1 = check_quote(str);
	if (quote1 == 1)
		even = check_quote_number(str, '\'');
	else if (quote1 == 2)
		even = check_quote_number(str, '\"');
	if (even == 0)
		return (NULL);
	// if (!var_in_quote(str, quote1))
		expanded = handle_dollar(str, i + 1, envlist, quote1);
		// printf("expanded %s", expanded);
	if (!expanded)
		return (NULL);
	free(str);
	str = expanded;
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
			// printf("expanded%s\n", expanded);
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