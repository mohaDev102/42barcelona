/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:24:36 by mel-atta          #+#    #+#             */
/*   Updated: 2023/12/30 02:24:38 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_not_found(char *cmd)
{
	write(2, "Error:\n", 7);
	write(2, "Command not found :", 20);
	write(2, &cmd[0], ft_strlen(&cmd[0]));
	write(2, "\n", 1);
	exit(127);
}

void	ft_iterar_paths(char **paths, char **cmd, char *env[])
{
	int		i;
	char	*path_cmd;
	char	*path;

	i = 0;
	path_cmd = NULL;
	while (paths[i] != NULL)
	{
		path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path, cmd[0]);
		execve(path_cmd, cmd, env);
		free(path);
		free(path_cmd);
		i++;
	}
}

void	ft_error(char *str, int error)
{
	perror(str);
	exit(error);
}
