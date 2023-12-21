#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipex.h"
#include <string.h>

void	ft_child(char *argv[], int *process_fd, char **env)
{
	int fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (access(argv[1], R_OK) == -1)
	{
		write(2, "permission denied\n", 18);
		exit(1);
	}	
	dup2(fd, STDIN_FILENO);
	dup2(process_fd[1], STDOUT_FILENO);
	close(process_fd[0]);
	//close(fd);
	ft_exec_cmd(&argv[2], env);
}

void	ft_parent(char *argv[], int *process_fd, char **env)
{
	int fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	// if (access(argv[4], F_OK) == -1)
	// {
	// 	write(2, "permission denied\n", 18);
	// 	exit(1);
	// }	
	// pid_t child_pid;
	// int status;
	dup2(fd, STDOUT_FILENO);
	dup2(process_fd[0], STDIN_FILENO);
	close(process_fd[1]);
	// child_pid = fork();
	// if (child_pid == 0)
	ft_exec_cmd(&argv[3], env);
	// waitpid(child_pid, &status, 0);
}

int main(int argc, char *argv[], char *env[]) 
{
	pid_t pid;
	int fd[2];

    if (argc != 5)
	{
        printf("Uso: %s <output_file1> <command1> <output_file2> <command2>\n", argv[0]);
		exit(1);
	}
    else
	{
		if (pipe(fd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		pid = fork();
		// exit(0);
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (pid == 0)
			ft_child(argv, fd, env);
		else
			ft_parent(argv, fd, env);
	}
	return (0);
}

