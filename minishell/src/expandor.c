/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:37 by alounici          #+#    #+#             */
/*   Updated: 2024/05/20 20:28:56 by alounici         ###   ########.fr       */
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

char *handle_dollar(char *str, int i, t_list **envlist)
{
	char *varname;
	char *res;

	// if (str[i] == "?")
	// {

	// }
	// else
	// {
		varname = extract_var_name(str, i);
				// printf("varname %s\n", varname);
		res = my_getenv(*envlist, varname, 0);
		// printf("res %s\n", res);

	// }
	return (res);
}

char *expand(char **str, int j, t_list **envlist)
{
    int	i;
	int cleaned;

	cleaned = 0;
	i = 0;
		(void)envlist;

	while (str[j][i])
	{
		if (str[j][i] == '\'')
		{
			str[j] = handle_quote(str[j], i, 1);
			cleaned = 1;
		}
		else if (str[j][i] == '\"')
		{
			str[j] = handle_quote(str[j], i, 2);
			cleaned = 1;
		}
		if (str[j][i] == '$')
		{
			str[j] = ft_strjoin(str[j], handle_dollar(str[j], i + 1, envlist));
			cleaned = 1;
		}
		i++;
	}
	if (cleaned == 1)
		return (str[j]);
	return(NULL);
}

int expandor(t_cmd *cmd, t_list **envlist)
{
    int i;
	char *expanded;
	// (void)envlist;
    i = 0;
    while (cmd)
    {

        while (cmd->args[i])
        {
			expanded = expand(cmd->args, i, envlist);
            if (expanded)
				cmd->args[i] = expanded;
			i++;
        }
        cmd = cmd->next;
    }
	return (0);
}