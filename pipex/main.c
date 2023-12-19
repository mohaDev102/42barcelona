#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipex.h"
#include <string.h>


char *ft_getenv(char *name, char *env[])
{
	int i;
	char **var;

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

char **find_path(char *env[])
{
	// buscar la ruta del comando que pongan por paramentro
	char **paths;
	char *path_sis;
	char **paths_pars = NULL;
	int i;
	int count;

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
	return (paths_pars);
}

void ft_exec_cmd(char *argv[], char *env[])
{
	char **paths;
	int i;

	paths = find_path(env);
	i = 0;
	while (paths[i] != NULL)
	{
		ft_check_cmd(paths[i], env, argv);
		i++;
	}
}

void	ft_child(char *argv[], int *process_fd, char **env)
{
	int fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		perror("open");
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
	if (fd == -1)
		perror("open");
	dup2(fd, STDOUT_FILENO);
	dup2(process_fd[0], STDIN_FILENO);
	close(process_fd[1]);
	//close(fd);
	ft_exec_cmd(&argv[3], env);
}

int main(int argc, char *argv[], char *env[]) 
{
	pid_t pid;
	int fd[2];

    if (argc != 5) 
        printf("Uso: %s <output_file1> <command1> <output_file2> <command2>\n", argv[0]);
    if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
    pid = fork();
    if (pid == -1)
    {
		perror("fork");
		exit(EXIT_FAILURE);
    }
    if (pid == 0)
		ft_child(argv, fd, env);
    else
		ft_parent(argv, fd, env);
	return (0);
}

