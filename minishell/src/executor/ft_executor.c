/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:01:02 by mel-atta          #+#    #+#             */
/*   Updated: 2024/06/02 13:11:25 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_cmd(t_cmd **cmd, t_list **envlist, char *myenv[], t_pipe *data)
{
	char	*path;
	char	**paths;

	path = NULL;
	path = ft_getenv("PATH", myenv);
	if (!path)
		return (ft_error_cmd(cmd, ": command not found\n"));
	paths = ft_split(path, ':');
	free(path);
	if (is_build(*cmd))
		exit(is_buildins(cmd, envlist, data));
	if ((*cmd)->args)
	{
		if (access(*(*cmd)->args, X_OK) != -1)
			execve((*cmd)->args[0], (*cmd)->args, myenv);
		search_path(paths, cmd, myenv);
	}
	free_split(paths);
	ft_error_cmd(cmd, ": command not found\n");
}

void	search_path(char **paths, t_cmd **cmd, char *env[])
{
	char	*path_final;
	char	*path_cmd;
	int		i;

	i = 0;
	while (paths[i] != NULL)
	{
		path_final = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path_final, *(*cmd)->args);
		if (!path_cmd)
			exit(-1);
		execve(path_cmd, (*cmd)->args, env);
		free(path_final);
		free(path_cmd);
		i++;
	}
}

int	is_build(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	if (tmp && tmp->args && tmp->args[0])
	{
		if (ft_strcmp(tmp->args[0], "echo") == 0)
			return (1);
		else if (ft_strcmp(tmp->args[0], "cd") == 0)
			return (1);
		else if (ft_strcmp(tmp->args[0], "unset") == 0)
			return (1);
		else if (ft_strcmp(tmp->args[0], "export") == 0 && tmp->args[1])
			return (1);
		else if (ft_strcmp(tmp->args[0], "env") == 0)
			return (1);
		else if (ft_strcmp(tmp->args[0], "exit") == 0)
			return (1);
		else if (ft_strcmp(tmp->args[0], "export") == 0)
			return (1);
		else if (ft_strcmp(tmp->args[0], "pwd") == 0)
			return (1);
	}
	return (0);
}

int	do_exec(t_cmd *aux, t_pipe *data, t_list **envlist, char *myenv[])
{
	int	i;

	i = -1;
	while ((aux) != NULL)
	{
		if (pipe(data->fd) == -1)
			return (-1);
		data->pid[++i] = fork();
		if (data->pid[i] == -1)
			return (-1);
		if (data->pid[i] == 0)
		{
			redirections(aux, *data);
			close_pipe(data->fd[0], data->fd[1]);
			exec_cmd(&aux, envlist, myenv, data);
		}
		dup2(data->fd[0], STDIN_FILENO);
		close_pipe(data->fd[0], data->fd[1]);
		(aux) = (aux)->next;
	}
	return (0);
}

int	executor(t_cmd **cmd, t_list **envlist, char *myenv[])
{
	t_pipe	*data;
	t_cmd	*aux;

	data = ft_pipes(cmd);
	if (data->n_commands == 1 && is_build(*cmd))
		return (is_buildins(cmd, envlist, data));
	aux = (*cmd);
	do_exec(aux, data, envlist, myenv);
	wait_children(data, 0);
	free_pipes(data);
	return (0);
}
