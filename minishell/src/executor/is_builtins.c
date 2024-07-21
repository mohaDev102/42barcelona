/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:15:13 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 13:16:27 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	echo_flag(char **args, int i)
{
	int	j;
	int	ret;

	ret = 0;
	j = 0;
	while (args[i])
	{
		if ((args[i][0] == '-' && args[i][1] == 'n'))
		{
			j = 1;
			while (args[i][j])
			{
				if (args[i][j] == 'n')
					j++;
				else
					return (ret);
			}
			ret++;
		}
		else
			return (ret);
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

int	dup_redir2(t_pipe *data)
{
	write(2, "Permission denied\n", 18);
	free_pipes(data);
	return (-1);
}

int	dup_redir(t_pipe *data, t_redir *temp)
{
	if (temp->type == INFILE || temp->type == HERDOC)
	{
		data->std_in = open(temp->file, O_RDONLY);
		if (data->std_in < 0)
			return (dup_redir2(data));
		dup2(data->std_in, STDIN_FILENO);
		close(data->std_in);
	}
	else if (temp->type == OUTFILE || temp->type == APPEND)
	{
		if (temp->type == OUTFILE)
			data->std_out = open(temp->file, O_WRONLY | O_CREAT | O_TRUNC,
					0644);
		else
			data->std_out = open(temp->file, O_WRONLY | O_CREAT | O_APPEND,
					0644);
		if (data->std_out < 0)
			return (dup_redir2(data));
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
