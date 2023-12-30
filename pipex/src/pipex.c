/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:21:37 by mel-atta          #+#    #+#             */
/*   Updated: 2023/12/30 02:21:43 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_child(char *argv[], int *process_fd, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": No such file or directory \n", 30);
	}
	else if (access(argv[1], R_OK) == -1)
	{
		write(2, "permission denied\n", 18);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	dup2(process_fd[1], STDOUT_FILENO);
	close(process_fd[0]);
	ft_exec_cmd(&argv[2], env);
}

void	ft_parent(char *argv[], int *process_fd, char **env)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		write(2, "Permission denied\n", 18);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	dup2(process_fd[0], STDIN_FILENO);
	close(process_fd[1]);
	ft_exec_cmd(&argv[3], env);
}

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
	{
		write(1, "./pipex infile command command outfile\n", 39);
		exit(1);
	}
	else
	{
		if (pipe(fd) == -1)
			ft_error("pipe", 1);
		pid = fork();
		if (pid == -1)
			ft_error("fork", 1);
		if (pid == 0)
			ft_child(argv, fd, env);
		else
			ft_parent(argv, fd, env);
	}
	return (0);
}
