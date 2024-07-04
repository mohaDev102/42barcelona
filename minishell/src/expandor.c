/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:37 by alounici          #+#    #+#             */
/*   Updated: 2024/07/04 19:28:05 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int check_quote(char *str, int i, int *count)
{
	int j;

	j = i + 1;
	*count += 1;
	while (str[j] && (str[j]!= str[i]))
	{
		j++;
	}
	if (str[j] == str[i])
		*count += 1;
	return(j - i);
}

int closed_quote(char *str)
{
	int i;
	int single;
	int doble;

	i = -1;
	single = 0;
	doble = 0;
	while (str[++i])
	{
		if (str[i] == '\'')
			i += check_quote(str, i, &single);
		if (str[i] == '\"')
			i += check_quote(str, i, &doble);
		if (str[i] == '\0')
			break;
	}
	if (((single > 0) && (single % 2 != 0)) || ((doble > 0) && (doble % 2 != 0)))
		return (0);
	return(1);
}


void quote_clean(char **str, int j, char *substr, int i)
{
	int l;
	int k;
	char c;
	int flag = 0;

	l = 0;
	c = str[j][i];
	printf("%c\n", str[j][i]);
		printf("d = %d\n", i);
	k = 0;
	// i++;
	while (l < i)
	{
		substr[k] = str[j][l];
		k++;
		l++;
		printf("copy 1%c, l %d\n", str[j][l], l);
	}
	// if (i > 0)
		l++; // += 1;
	while (str[j][l]) 
	{

		if ((str[j][l] == c && flag == 0))// || l == i)
		{

		printf("perd %c, l %d\n", str[j][i], l);
			// if (l != i)
				flag = 1;
		}
		else //if (str[j][l] != c || (str[j][l] == c && flag == 1))
		{
			substr[k] = str[j][l];
		printf("copy 2%c, l %d\n", str[j][l], l);

			k++;
		}
		l++;
		// if (flag == 1)
	}
	substr[k] = '\0';
		printf("subst %s\n", substr);
	// if (strchr(str[j], '$') != 0)
		free(str[j]);
	str[j] = ft_strdup(substr);
	free(substr);
		// printf("sust %s\n", substr);

}
int quote_erase(char **str, int j, int i)
{
	char *substr;
	int k;
	char quote;

	k = 0;
	// i++;
	quote = str[j][i];
	// i += 1;
	substr = malloc(sizeof(char) * (ft_strlen(str[j])));
	if (substr == NULL)
		return (-1);
	quote_clean(str, j, substr, i);
	// printf("str %s\n", str[j]);
	// free(substr);
	while (str[j][k++] && str[j][k] != quote)
    {
        continue;
    }
    // if (str[j][i + k] && str[j][i + k] == quote)
    // {
    //     k++;
    // }
	// }
	return(k);
}

void 	handle_quote(char **str, int j, int flag)
{
	int i;
	int k;
	char *new_str;

    (void)flag;
    i = 0;
    k = 0;
	if (closed_quote(str[j]) == 0)
    {
		// write(1, "ici", 3);
    	new_str = ft_strdup("");
        if (!new_str)
        {
            free(str[j]);
            return ;
        }
		// free(str[j]);
        str[j] = ft_strdup(new_str);
		free(new_str);
    }
	else
	{
		while (str[j][i])
		{
			if (str[j][i] == '\'' || str[j][i] == '\"')
			{		
				// write(2, "ici\n", 4);
				// printf("char clean%c\n", str[j][i]);
				k = quote_erase(str, j, i);
				if (k == 0)
					return ;
				// if (str[j][k] == str[j][i])
				// 	k++;
				// else
					i = k - 1;
				// printf("k = %d i = %d\n", k, i);
			}
			else
				i++;
		}

	}
}

char *handle_dollar(char *str, int i, t_list **envlist, int quote)
{
	char **splited;
	char *res;
	char *aux;
	char *auxbis;
	// char *left;
	// char *first;
	// int i;

	i = 0;
	(void)quote;
	res = NULL;
	if (strchrint(str, '$') == (ft_strlen(str) - 1))
		return(ft_strdup(str));
    splited = ft_split(str, '$');
		while (splited[i])
		{
		// write(1, "ici", 3);
		printf("split %s\n", splited[i]);
		if (ft_strchr(splited[i], '$'))
		{
			aux = extract_var_name(splited[i], 0);
			auxbis = my_getenv(*envlist, aux, 3, 1);

		}
		else
			aux = splited[i];
		// printf("aux %s\n", aux);
			// if (auxbis == NULL)
			// 	auxbis = NULL;
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
			free(splited[i]);
			i++;
		}
		// free(aux);
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
			handle_quote(str, j, 0);
			// printf("str %s", str[j]);
			cleaned = 1;
		}
		else if (str[j][i] == '\"')
		{
			handle_quote(str, j, 0);
			// printf("str %s", str[j]);
			cleaned = 2;
		}
	return (cleaned);
}
// int	check_quote(char *str)
// {
// 	int i;

// 	while(str[i])
// 	{
// 		if (str[i] == '\'')
// 			return (1);
// 		if (str[i] == '\"')
// 			return (2);
// 		i++;
// 	}
// 	return (0);
// }

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
	if (str[j][i] == '\"' && (ft_strchr(str[j], '$') != 0))
	{
		tmp = str[j];
		// free(str[j]);
		str[j] = dollar(tmp, i, envlist, 2);
		if (str[j] == NULL)
			return (ft_strdup(""));
		// printf("quote%s\n", str[j]);
		// write(1, "ici", 3);
		// printf("res av quoyte%s", str[j]);
		handle_quote(str, j, 1);
		// free(tmp);
		// free(res);
		return (str[j]);
	}
	else
	{
		cleaned = quote_found(str, j, i);
		if (cleaned == 0 || str[j] == NULL) // || !str[j][i])
			return (NULL);
		return (str[j]);
		
	}
	return (NULL);
}
int all_quote(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\"'  && str[i] != '\'')
			return (1);
		i++;
	}
	return (0);
}


char *expand(char **str, int j, t_list **envlist)
{
    int	i;
	int cleaned;
	char *tmp;
	int flag;

	flag = 0;
	cleaned = 0;
	i = 0;
	// controlar comillas
	if (!str[j] || ft_strcmp(str[j], "\"\"") == 0)
		return (NULL);
	while (str[j][i])
	{
		if ((str[j][i] == '\'' || str[j][i] == '\"') && cleaned == 0)
		{
			if (all_quote(str[j]) == 1)
			{
				// return(NULL);
				tmp = str[j];
				flag = 1;
			}
			str[j] = quote(str, j, i, envlist);
			if (flag == 1)
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

//exit dentro de ./mini