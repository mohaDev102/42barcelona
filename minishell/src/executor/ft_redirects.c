/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:42:57 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/28 11:45:17 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	redirections(t_cmd **cmd, t_pipe data, char *env[])
{
	int		fd;
	t_redir	*aux;

    fd = 0;
	(void)env;
	if ((*cmd)->next)
		dup2(data.fd[1], STDOUT_FILENO);
	aux = (*cmd)->redir;
	while (aux)
	{
		infile_herdoc(aux, fd);
		outfile(aux, fd);
		append(aux, fd);
		aux = aux->next;
	}
}

int	parser_lstsize(t_cmd *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_pipe	*ft_pipes(t_cmd **cmd)
{
	t_pipe	*data;

	data = malloc(sizeof(t_pipe));
	if (!data)
		return (NULL);
	data->n_commands = parser_lstsize(*cmd);
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->pid = malloc(sizeof(pid_t) * data->n_commands);
	if (!data->pid)
		return (NULL);
	data->std_in = dup(STDIN_FILENO);
	data->std_out = dup(STDOUT_FILENO);
    return (data);
}

void	ft_error_cmd(t_cmd **cmd, char *msg)
{
	if ((*cmd)->args)
	{
		if (access(*(*cmd)->args, F_OK) == -1)
		{
			if (msg != NULL)
				write(2, msg, ft_strlen(msg));
			exit(127);
		}
	}
}
void	close_pipe(int in, int out)
{
	if (in != -1)
		close(in);
	if (out != -1)
		close(out);
}
