/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_buildins2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:00:10 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 13:16:22 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	is_buildins2(t_cmd *tmp, t_list **envlist)
{
	int	i;

	i = 1;
	if (ft_strcmp(tmp->args[0], "cd") == 0)
		ft_cd(tmp->args[1], envlist);
	else if (ft_strcmp(tmp->args[0], "unset") == 0)
		while (tmp->args[i])
			ft_unset(envlist, tmp->args[i++]);
	else if (ft_strcmp(tmp->args[0], "export") == 0 && tmp->args[1])
		while (tmp->args[i])
			ft_export(envlist, tmp->args[i++]);
	else if (ft_strcmp(tmp->args[0], "export") == 0)
		ft_export_alone(envlist);
	else if (ft_strcmp(tmp->args[0], "env") == 0)
		ft_env(envlist);
	else if (ft_strcmp(tmp->args[0], "exit") == 0)
		ft_exit(tmp->args);
	else if (ft_strcmp(tmp->args[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(tmp->args[0], "~") == 0)
		ft_tilde(*envlist);
}

int	is_buildins(t_cmd **cmd, t_list **envlist, t_pipe *data)
{
	t_cmd	*tmp;
	int		std_out;
	int		std_in;

	std_in = dup(STDIN_FILENO);
	std_out = dup(STDOUT_FILENO);
	tmp = *cmd;
	if (manage_redir(*cmd, data) == -1)
	{
		dup2(std_in, STDIN_FILENO);
		dup2(std_out, STDOUT_FILENO);
		return (0);
	}
	if (tmp && tmp->args && tmp->args[0])
	{
		is_echo(&tmp, *envlist);
		is_buildins2(tmp, envlist);
	}
	dup2(std_in, STDIN_FILENO);
	dup2(std_out, STDOUT_FILENO);
	close(std_in);
	close(std_out);
	free_pipes(data);
	return (0);
}

int	exec_echo_n(int nindex, char **args, t_list *envlist)
{
	int	i;
	int	auxindex;

	auxindex = nindex;
	i = 0;
	while (args[i])
		i++;
	if (nindex != 0)
	{
		nindex++;
		while (args[nindex])
		{
			ft_echo(args[nindex++], 0, envlist);
			if (i - nindex >= 1 && nindex > auxindex)
				write(1, " ", 1);
		}
		return (1);
	}
	return (0);
}

void	exec_echo(int i, char **args, t_list *envlist)
{
	while (args[i])
	{
		if (i > 1)
			write(1, " ", 1);
		ft_echo(args[i++], 1, envlist);
	}
	write(1, "\n", 1);
}

int	is_echo(t_cmd **tmp, t_list *envlist)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (ft_strcmp((*tmp)->args[i], "echo") == 0)
	{
		ret = echo_flag(&(*tmp)->args[i], i + 1);
		if (exec_echo_n(ret, (*tmp)->args, envlist) == 1)
			return (1);
		else
		{
			i++;
			exec_echo(i, (*tmp)->args, envlist);
			return (1);
		}
	}
	i++;
	return (0);
}
