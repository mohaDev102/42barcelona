/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:37 by alounici          #+#    #+#             */
/*   Updated: 2024/06/29 02:31:57 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


char	*handle_quote(char *str, int i, int flag)
{
	char c;
	char *res;

	c = str[i];
	if (!str)
		return (str);
	res = clean_str(str, c, check_quote_number(str, c, i), flag);
	return (res);
}

char *handle_dollar(char *str, int i, t_list **envlist, int quote)
{
	char **splited;
	char *res;
	char *aux;
	char *auxbis;
	char *left;
	char *first;
	// int i;

	i = 0;
	(void)quote;
	res = NULL;
	if (strchrint(str, '$') == (ft_strlen(str) - 1))
		return(ft_strdup(str));
    splited = ft_split(str, '$');
	// if (splited == NULL)
	// {
	// 	free(splited);
	// 	aux = extract_var_name(str, 0);
	// 	// printf("aux %s", aux);
	// 	auxbis = my_getenv(*envlist, aux, 3, 0);
	// 	free(aux);
	// 	if (auxbis == NULL)
	// 	{
	// 		free(aux);
	// 		return(ft_strdup(""));
	// 	}
	// 	return(auxbis);
	// 	// free(auxbis);
	// }
	// else
	// {
		while (splited[i])
		{
		write(1, "ici", 3);
		// printf("split %s\n", splited[i]);
			aux = extract_var_name(splited[i], 0);
		// printf("aux %s\n", aux);
			auxbis = my_getenv(*envlist, aux, 3, 1);
			// if (auxbis == NULL)
			// 	auxbis = NULL;
			free(splited[i]);
			free(aux);
			if (res != NULL)
			{
				char *temp = ft_strjoinexp(res, auxbis);
				free(res);
				res = temp;
				free(auxbis);
			}
			else if (auxbis)
			{
				
				char *temp = ft_strdup(auxbis);
				res = temp;
				free(auxbis);
			}
			// if (quote != 0)
			// free(splited[i]);
			i++;
		}
	// }
	first = text_before_var(str);
	left = text_after_var(str);
	if (left != NULL)
	{
		char *temp = ft_strjoin(res, left);
		free(res);
		res = temp;
	}
	if (first != NULL)
	{
		// printf("first %s", first);
		char *temp = ft_strjoin(first, res);
		free(res);
		res = temp;
	}
	free(left);
	free(first);
	// if (quote == 0)
	// 	free(auxbis);
	// if (quote != 0)
	free(splited);
	return (res);
}

int	ft_strlenexp2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\"')
			i++;
	}
	return(i);
}


char	*ft_strjoinexp(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlenexp2(s1) + ft_strlenexp2(s2);
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	// free(s1);
	// if (s2)
	// 	free(s2);
	return (res);
}
// char *handle_dollar(char *str, int i, t_list **envlist, int quote)
// {
// 	char	*var_content;
// 	char	**res;
// 	int		j;
// 	char	*aux;
// 	char *var;

// 	j = 1;
// 	if (!str || ft_strlen(str) == 1)
// 		return (NULL);
// 	if (str[i] == '?' && (quote == 0 || quote == 2))
// 	{
// 		free(str);
// 		var_content = last_exit();
// 		return (var_content);
// 	}
// 	else if (quote == 1 || quote == 2 || quote == 0)
// 	{

// 		res = manage_first_dollar(str, envlist);
// 		if (!res[0] || !res)
// 			return (NULL);
// 		// var = res[0];
// 	// var_content = malloc(sizeof(char) * (ft_strlen(res[0]) + 1));
// 		var_content = ft_strdup(res[0]);
// 		// exit(1);
// 		if (res[1])
// 		{
// 		// free(res[0]);
// 			while (res[j])
// 			{
// 				// free(var);
// 				var = res[j];
// 				aux = my_getenv(*envlist, var, 3, 1);
// 				if (aux != NULL)
// 					var_content = ft_strjoin(var_content, aux);
// 				else
// 					var_content = ft_strjoin(var_content, res[j]);
// 				j++;
// 			}
// 		}
// 	// i = 0;
// 	// while (res[i])
// 	// {
// 	// 	printf("res%s\n", res[i]);
// 	// 	i++;
// 	// }
// 		// free(str);
// 	}
// 		if (quote == 2)
// 			free_split(res);
// 		else
// 			free(res);
// 	// else
// 	// 	return (str);
// 		// free(var);
// 	return (var_content);
// }

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
			str[j] = handle_quote(str[j], i, 0);
			cleaned = 1;
		}
		else if (str[j][i] == '\"')
		{
			str[j] = handle_quote(str[j], i, 0);
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
	char *res;

	(void)quote;
	even = check_quote_number_dollar(str);
	if (even == 0)
		return (NULL);
	res = handle_dollar(str, i + 1, envlist, quote);
	// printf("dolar res = %s", res);
	// free(str);
	// if (!res)
	// 	return (NULL);
	return (res);
}

char *quote(char **str, int j, int i, t_list **envlist)
{
	int cleaned;
	char *tmp;
	// char *res;

	cleaned = 0;
	if (str[j][i] == '\"' && (ft_strchr(str[j], '$') != NULL))
	{
		tmp = str[j];
		// free(str[j]);
		str[j] = dollar(tmp, i, envlist, 2);
		// printf("res %s", res);
		// str[j] = handle_quote(res, i, 1
		// free(tmp);
		// free(res);
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
	char *tmp;

	cleaned = 0;
	i = 0;
	if (!str[j])
		return (NULL);
	while (str[j][i])
	{
		if ((str[j][i] == '\'' || str[j][i] == '\"') && cleaned == 0)
		{
			tmp = str[j];
			str[j] = quote(str, j, i, envlist);
			free(tmp);
			return (str[j]);
		}
		else if (str[j][i] == '$')
		{
			tmp = str[j];
			str[j] = dollar(str[j], i, envlist, cleaned);
			free(tmp);
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
			{
				free(cmd->args[i]);
				cmd->args[i] = expanded;
			}
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