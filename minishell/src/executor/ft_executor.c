/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:01:02 by mel-atta          #+#    #+#             */
/*   Updated: 2024/06/02 11:50:02 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	wait_children(t_pipe *info, int *exit)
{
	int	i;
	int	status;

	(void)exit;
	i = 0;
	while (i < info->n_commands)
	{
		waitpid(info->pid[i], &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		
		i++;
	}
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			status = 131;
		else if (WTERMSIG(status) == SIGTERM)
			status = 130;
	}
	// printf("status %d", status);
	dup2(info->std_in, STDIN_FILENO);
	dup2(info->std_out, STDOUT_FILENO);
	free(info->pid);
	exit_status(status);
}
char	*ft_getenv(char *name, char *env[])
{
	int		i;
	char	**var;

	i = 0;
	while (env[i] != NULL)
	{
		var = ft_split(env[i], '=');
		if (var != NULL && var[0] != NULL && var[1] != NULL)
		{
			if (ft_strcmp(var[0], name) == 0)
				return (var[1]);
		}
		free(var);
		i++;
	}
	return (NULL);
}

void	search_path(t_cmd **cmd, char *env[], t_list **envlist, char *myenv[], t_pipe *data)
{
	char	*path;
	char	**paths;
	char	*path_cmd;
	char	*path_final;
	int		i;

	path_cmd = NULL;
	path = NULL;
	i = 0;
	path = ft_getenv("PATH", myenv);
	if (!path)
		return ft_error_cmd(cmd, "command not found\n");
	paths = ft_split(path, ':');
	if (is_build(*cmd, envlist))
		exit(is_buildins(cmd, envlist, data));
	if ((*cmd)->args)
	{
		if (access(*(*cmd)->args, X_OK) != -1)
			execve((*cmd)->args[0], (*cmd)->args, env);
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
	ft_error_cmd(cmd, " : command not found");
}

void	exec_cmd(char *path, t_cmd **cmd, char *env[])
{
	(void)path;
	(void)cmd;
	(void)env;
}

int	is_build(t_cmd *cmd, t_list **envlist)
{
	int		i;
	t_cmd	*tmp;

	tmp = cmd;
	i = 1;
	(void)envlist;
	if (tmp && tmp->args && tmp->args[0])
	{
		// if (tmp && tmp->args && tmp->args[0])
		// {
		// if (is_buildins2(&tmp, *envlist) == 1)
		//     return (1);
		if (ft_strcmp(tmp->args[0], "echo") == 0)
		    return (1);
		else if (ft_strcmp(tmp->args[0], "cd") == 0)
			return (1);
		else if (ft_strcmp(tmp->args[0], "unset") == 0)
			return (1);
		else if (ft_strcmp(tmp->args[0], "export") == 0 && tmp->args[1])
		{
			// write(1, "ici", 3);
			return (1);
		}
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

int	executor(t_cmd **cmd, char **env, t_list **envlist, char *myenv[])
{
	t_pipe	data;
	int		i;
	int status;

	status = 0;
	i = -1;
	data = *ft_pipes(cmd);
	if (data.n_commands == 1 && is_build(*cmd, envlist))
		return (is_buildins(cmd, envlist, &data));
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
			search_path(cmd, env, envlist, myenv, &data);
		}
		dup2(data.fd[0], STDIN_FILENO);
		close_pipe(data.fd[0], data.fd[1]);
		(*cmd) = (*cmd)->next;
	}
	// exit_status(WSTOPSIG(status));
	wait_children(&data, 0);
	return (0);
}

// int executor(t_cmd **cmd, t_lexer **lexer, char **env)
// {
//     t_pipe data;
//     int i = 0;
//     (void) lexer;
//     data.n_commands = parser_lstsize(*cmd);
//     // data.n_commands = 1;
//     data.fd[0] = -1;
//     data.fd[1] = -1;
//     data.pid = malloc(sizeof(pid_t) * data.n_commands);
//     if (!data.pid)
//         return (-1);
//     data.std_in = dup(STDIN_FILENO);
//     data.std_out = dup(STDOUT_FILENO);
//     // is_buildins(cmd, );
//     while ((*cmd) != NULL)
//     {
//         if (pipe(data.fd) == -1)
//             return (-1);
//         data.pid[i] = fork();
//         if (data.pid[i] == -1)
//             return (-1);
//         if (data.pid[i] == 0)
//         {
//             if ((*cmd)->next)
//                 dup2(data.fd[1], STDOUT_FILENO);
//             //redirections(cmd, data, env);
//             close(data.fd[1]);
//             close(data.fd[0]);
//             search_path(cmd, env);
//         }
//         // mirar los permisos y luego poner command not found
//             // execve("/bin/ls", (*cmd)->args, env);
//             // exec_cmd(path, cmd, env);
//         dup2(data.fd[0], STDIN_FILENO);
//         close_pipe(data.fd[0], data.fd[1]);
//         (*cmd) = (*cmd)->next;
//         // printf("arg = %s", (*cmd)->args[1]);
//         i++;
//     }

//     // tengo que hay el wait_children
//     // printf("%d", i);
//     wait_children(&data, 0);
//     return (0);
// }
