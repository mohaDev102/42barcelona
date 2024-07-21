/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:37 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 11:50:24 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*expand(char **str, int j, t_list **envlist)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str[j] || ft_strcmp(str[j], "\"\"") == 0)
		return (NULL);
	if (ft_strchr(str[j], '\'') != NULL || ft_strchr(str[j], '\"') != NULL)
	{
		str[j] = quote(str, j, i, envlist);
		return (str[j]);
	}
	if (ft_strchr(str[j], '$') != NULL)
	{
		tmp = str[j];
		str[j] = dollar(str[j], i, envlist);
		free(tmp);
		return (str[j]);
	}
	return (str[j]);
}

int	redir_exp(t_redir *tmp, t_list **envlist)
{
	while (tmp)
	{
		if (expand(&(tmp->file), 0, envlist))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	expandor(t_cmd *cmd, t_list **envlist)
{
	int		i;
	char	*expanded;
	t_redir	*tmp;

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
		if (!redir_exp(tmp, envlist))
			return (0);
		cmd = cmd->next;
	}
	return (0);
}

// exit dentro de ./mini