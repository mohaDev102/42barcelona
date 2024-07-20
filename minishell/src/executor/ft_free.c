/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:45:02 by mel-atta          #+#    #+#             */
/*   Updated: 2024/07/17 19:23:14 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

char	*ft_getenv(char *name, char *env[])
{
	int		i;
	char	**var;
	char	*result;

	i = 0;
	while (env[i] != NULL)
	{
		var = ft_split(env[i], '=');
		if (var != NULL && var[0] != NULL && var[1] != NULL)
		{
			if (ft_strcmp(var[0], name) == 0)
			{
				result = ft_strdup(var[1]);
				free_split(var);
				return (result);
			}
		}
		free_split(var);
		i++;
	}
	return (NULL);
}

void	free_pipes(t_pipe *data)
{
	if (!data)
		return ;
	if (data)
	{
		close(data->std_in);
		close(data->std_out);
		data->n_commands = 0;
	}
	if (data->pid != NULL)
		free(data->pid);
	free(data);
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
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		i++;
	}
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			status = 131;
		else if (WTERMSIG(status) == SIGINT)
			status = 130;
	}
	dup2(info->std_in, STDIN_FILENO);
	dup2(info->std_out, STDOUT_FILENO);
	// printf("status %d\n", status);
	exit_status(status);
}
