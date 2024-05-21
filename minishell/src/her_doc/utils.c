/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:43:05 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/21 14:30:16 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	infile_herdoc(t_redir *aux, int fd)
{
	if (aux->type == INFILE || aux->type == HERDOC)
	{
		fd = open(aux->file, O_RDONLY);
		if (fd < 0)
		{
			if (access(aux->file, F_OK) == -1)
			{
				write(2, "no such file or directory: ", 28);
				write(2, aux->file, ft_strlen(aux->file));
				write(2, "\n", 2);
				exit(1);
			}
			else
			{
				write(2, "Permission denied\n", 19);
				exit(126);
			}
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	outfile(t_redir *aux, int fd)
{
	if (aux->type == OUTFILE)
	{
		fd = open(aux->file, O_CREAT | O_WRONLY | O_TRUNC, 0755);
		if (fd < 0)
		{
			if (access(aux->file, X_OK) == -1)
				write(2, "Permission denied\n", 19);
			exit(126);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

void	append(t_redir *aux, int fd)
{
	if (aux->type == APPEND)
	{
		fd = open(aux->file, O_CREAT | O_WRONLY | O_APPEND, 0755);
		if (fd < 0)
		{
			if (access(aux->file, X_OK) == -1)
				write(2, "Permission denied\n", 19);
			exit(126);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}
