/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:21:57 by mel-atta          #+#    #+#             */
/*   Updated: 2023/12/30 02:21:59 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	**find_path(char *env[])
{
	char	**paths;
	char	*path_sis;
	char	**paths_pars;
	int		i;
	int		count;

	paths_pars = NULL;
	i = 0;
	count = 0;
	path_sis = ft_getenv("PATH", env);
	paths = ft_split(path_sis, ':');
	while (paths[count] != NULL)
		count++;
	paths_pars = (char **)malloc((count + 1) * sizeof(char *));
	while (paths[i] != NULL)
	{
		paths_pars[i] = paths[i];
		i++;
	}
	paths_pars[i] = NULL;
	return (paths_pars);
}

char	*ft_check_cmd(char *env[], char *argv[])
{
	char	**cmd;
	char	**paths;

	paths = find_path(env);
	cmd = ft_split(*argv, ' ');
	if (access(cmd[0], X_OK) != -1)
		execve(cmd[0], cmd, env);
	else if (access(cmd[0], X_OK) == -1)
		ft_iterar_paths(paths, cmd, env);
	if (access(cmd[0], F_OK) != -1)
	{
		write(2, "Permission denied\n", 18);
		exit(126);
	}
	else
	{
		if (cmd[0] != NULL)
			ft_not_found(*cmd);
	}
	free(cmd);
	return (NULL);
}

void	ft_exec_cmd(char *argv[], char *env[])
{
	char	**paths;

	paths = find_path(env);
	ft_check_cmd(env, argv);
}
