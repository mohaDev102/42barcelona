/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:01:02 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/21 14:31:52 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	close_pipe(int in, int out)
{
	if (in != -1)
		close(in);
	if (out != -1)
		close(out);
}

void	wait_children(t_pipe *info, int *exit)
{
	int	i;
	int	status;

	(void)exit;
	i = 0;
	while (i < info->n_commands)
	{
		waitpid(info->pid[i], &status, 0);
		i++;
	}
	dup2(info->std_in, STDIN_FILENO);
	dup2(info->std_out, STDOUT_FILENO);
	free(info->pid);
	// if (WIFEXITED(status))
	//     *exit = (WIFEXITED(status));
	// señales
	// else if ()
	// {
	// }
}

void	search_path(t_cmd **cmd, char *env[])
{
	char	*path;
	char	**paths;
	char	*path_cmd;
	char	*path_final;
	int		i;

	path_cmd = NULL;
	i = 0;
	path = getenv("PATH");
	if (!path)
		exit(1);
	paths = ft_split(path, ':');
	if (access(*(*cmd)->args, X_OK) != -1)
		execve((*cmd)->args[0], (*cmd)->args, env);
	while (paths[i] != NULL)
	{
		path_final = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path_final, *(*cmd)->args);
		execve(path_cmd, (*cmd)->args, env);
		free(path_final);
		free(path_cmd);
		i++;
	}
	ft_error_cmd(cmd, "Command not found\n");
}

void	exec_cmd(char *path, t_cmd **cmd, char *env[])
{
	(void)path;
	(void)cmd;
	(void)env;
}

int	executor(t_cmd **cmd, char **env)
{
	t_pipe	data;
	int		i;

	i = -1;
	data = *ft_pipes(cmd);
	while ((*cmd) != NULL)
	{
		if (pipe(data.fd) == -1)
			return (-1);
		data.pid[++i] = fork();
		if (data.pid[i] == -1)
			return (-1);
		if (data.pid[i] == 0)
		{
			redirections(cmd, data, env);
			close(data.fd[1]);
			close(data.fd[0]);
			search_path(cmd, env);
		}
		dup2(data.fd[0], STDIN_FILENO);
		close_pipe(data.fd[0], data.fd[1]);
		(*cmd) = (*cmd)->next;
	}
	wait_children(&data, 0);
	return (0);
}
