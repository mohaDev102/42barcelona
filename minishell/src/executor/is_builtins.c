/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:15:13 by alounici          #+#    #+#             */
/*   Updated: 2024/06/02 13:11:32 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// echo $?
// cd ok
// unset path

int	echo_flag(char **args, int i)
{
	int	j;
	int	ret;

	ret = 0;
	j = 0;
	while (args[i])
	{
		if (args[i][0] == '-' && args[i][1] == 'n' && (ft_strcmp(args[i - 1],
				"echo") == 0 || ft_strcmp(args[i - 1], "-n") == 0 || \
					args[i - 1][ft_strlen(args[i - 1]) - 1]))
		{
			j = 1;
			while (args[i][j] == 'n')
			{
				j++;
			}
			ret++;
		}
		i++;
	}
	return (ret);
}

void	unlink_herdoc(t_redir *redir)
{
	while (redir)
	{
		if (redir->type == HERDOC)
			unlink(redir->file);
		redir = redir->next;
	}
}

int	dup_redir(t_pipe *data, t_redir *temp)
{
	if (temp->type == INFILE || temp->type == HERDOC)
	{
		data->std_in = open(temp->file, O_RDONLY);
		if (data->std_in < 0)
		{
			write(2, "Permission denied\n", 18);
			return (-1);
		}
		dup2(data->std_in, STDIN_FILENO);
		close(data->std_in);
	}
	else if (temp->type == OUTFILE || temp->type == APPEND)
	{
		if (temp->type == OUTFILE)
			data->std_out = open(temp->file, O_WRONLY | \
			O_CREAT | O_TRUNC, 0644);
		else
			data->std_out = open(temp->file, O_WRONLY | O_CREAT | O_APPEND,
					0644);
		if (data->std_out < 0)
		{
			write(2, "Permission denied\n", 18);
			return (-1);
		}
		dup2(data->std_out, STDOUT_FILENO);
		close(data->std_out);
	}
	return (0);
}

int	manage_redir(t_cmd *cmd, t_pipe *data)
{
	t_redir	*temp;

	temp = cmd->redir;
	while (temp)
	{
		if (dup_redir(data, temp) == -1)
		{
			unlink_herdoc(cmd->redir);
			return (-1);
		}
		temp = temp->next;
	}
	unlink_herdoc(cmd->redir);
	return (0);
}

int	is_buildins2(t_cmd **tmp, t_list *envlist)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	ret = 0;
	while ((*tmp)->args[i])
	{
		if (ft_strcmp((*tmp)->args[i], "echo") == 0)
		{
			ret = echo_flag(&(*tmp)->args[i], i);
			if (ret != 0)
			{
				ret++;
				while ((*tmp)->args[ret])
					ft_echo((*tmp)->args[ret++], 0, envlist);
				return (1);
			}
			else
			{
				i++;
				while ((*tmp)->args[i])
				{
					if (i > 1)
						write(1, " ", 1);
					ft_echo((*tmp)->args[i++], 1, envlist);
				}
				write(1, "\n", 1);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	is_buildins(t_cmd **cmd, t_list **envlist, t_pipe *data)
{
	int		i;
	t_cmd	*tmp;
	int		std_out;
	int		std_in;

	std_in = dup(STDIN_FILENO);
	std_out = dup(STDOUT_FILENO);
	i = 1;
	tmp = *cmd;
	if (manage_redir(*cmd, data) == -1)
	{
		dup2(std_in, STDIN_FILENO);
		dup2(std_out, STDOUT_FILENO);
		return (0);
	}
	if (tmp && tmp->args && tmp->args[0])
	{
		if (ft_strcmp(tmp->args[0], "echo") == 0)
			is_buildins2(&tmp, *envlist);
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
	}
	dup2(std_in, STDIN_FILENO);
	dup2(std_out, STDOUT_FILENO);
	close(std_in);
	close(std_out);
	free_pipes(data);
	return (0);
}
